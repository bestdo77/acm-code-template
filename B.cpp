#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <mpi.h>

using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Matrix {
public:
    Matrix(int rows, int cols) 
        : rows_(rows), cols_(cols), data_(rows * cols) {}
    
    int* data() { return data_.data(); }
    const int* data() const { return data_.data(); }
    
    int& operator()(int row, int col) { 
        return data_[row * cols_ + col];
    }
    const int& operator()(int row, int col) const { 
        return data_[row * cols_ + col];
    }
    
    int rows() const { return rows_; }
    int cols() const { return cols_; }

    void resize(int rows, int cols) {
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
    }

private:
    int rows_, cols_;
    vector<int> data_;
};

void local_matmul_optimized(const Matrix& A, const Matrix& B, Matrix& C) {
    const int K = A.cols();
    const int M = B.cols();
    const int A_rows = A.rows();
    
    fill(C.data(), C.data() + C.rows()*C.cols(), 0);
    
    #pragma omp parallel for num_threads(64) collapse(2) if (A_rows*M > 10000)
    for (int i = 0; i < A_rows; ++i) {
        for (int j = 0; j < M; ++j) {
            int sum = 0;
            for (int k = 0; k < K; ++k) {
                sum += A(i, k) * B(k, j);
            }
            C(i, j) = sum;
        }
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0 && argc < 4) {
        cerr << "Usage: " << argv[0] 
             << " <testcase_count> [N K M]...\n";
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int testcase_count = 0;
    vector<int> params;
    if (rank == 0) {
        testcase_count = atoi(argv[1]);
        params.reserve(3 * testcase_count);
        for (int i = 0; i < testcase_count; ++i) {
            params.push_back(atoi(argv[2 + 3*i]));
            params.push_back(atoi(argv[3 + 3*i]));
            params.push_back(atoi(argv[4 + 3*i]));
        }
    }
    
    MPI_Bcast(&testcase_count, 1, MPI_INT, 0, MPI_COMM_WORLD);
    params.resize(3 * testcase_count);
    MPI_Bcast(params.data(), 3 * testcase_count, MPI_INT, 0, MPI_COMM_WORLD);

    vector<int> counts(size), displs(size);
    vector<int> send_counts(size), send_displs(size);

    for (int t = 0; t < testcase_count; ++t) {
        const int N = params[3*t];
        const int K = params[3*t+1];
        const int M = params[3*t+2];

        Matrix A_local(0, K), B(K, M), C_local(0, M);
        
        if (rank == 0) {
            int base = N / size;
            int remainder = N % size;
            for (int i = 0; i < size; ++i) {
                counts[i] = base + (i < remainder ? 1 : 0);
                displs[i] = (i == 0) ? 0 : displs[i-1] + counts[i-1];
                send_counts[i] = counts[i] * K;
                send_displs[i] = displs[i] * K;
            }
        }
        
        MPI_Bcast(counts.data(), size, MPI_INT, 0, MPI_COMM_WORLD);
        
        if (rank == 0) {
            Matrix A_global(N, K);
            Matrix B_global(K, M);
            
            uniform_int_distribution<int> dist(0, 99);
            for (int i = 0; i < N*K; ++i) 
                A_global.data()[i] = dist(RNG);
            for (int i = 0; i < K*M; ++i) 
                B_global.data()[i] = dist(RNG);

            A_local.resize(counts[0], K);
            memcpy(A_local.data(), A_global.data(), counts[0]*K*sizeof(int));

            MPI_Request* requests = new MPI_Request[size-1];
            for (int i = 1; i < size; ++i) {
                MPI_Isend(A_global.data() + send_displs[i], send_counts[i], 
                        MPI_INT, i, 0, MPI_COMM_WORLD, &requests[i-1]);
            }

            // 等待所有发送完成
            MPI_Waitall(size-1, requests, MPI_STATUSES_IGNORE);
            delete[] requests;

            // 同步广播B的数据
            MPI_Bcast(B_global.data(), K*M, MPI_INT, 0, MPI_COMM_WORLD);
            B = B_global;
        } else {
            const int local_rows = counts[rank];
            A_local.resize(local_rows, K);
            // 接收A的数据
            MPI_Recv(A_local.data(), local_rows*K, MPI_INT, 
                    0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            // 同步接收B的广播
            MPI_Bcast(B.data(), K*M, MPI_INT, 0, MPI_COMM_WORLD);
        }

        C_local.resize(counts[rank], M);
        
        MPI_Barrier(MPI_COMM_WORLD);
        auto start = chrono::high_resolution_clock::now();
        local_matmul_optimized(A_local, B, C_local);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        
        Matrix C_global(N, M);
        vector<int> recv_counts(size), recv_displs(size);
        
        if (rank == 0) {
            for (int i = 0; i < size; ++i) {
                recv_counts[i] = counts[i] * M;
                recv_displs[i] = (i == 0) ? 0 : recv_displs[i-1] + recv_counts[i-1];
            }
        }
        
        MPI_Gatherv(C_local.data(), counts[rank]*M, MPI_INT,
                  C_global.data(), recv_counts.data(), recv_displs.data(),
                  MPI_INT, 0, MPI_COMM_WORLD);
        
        if (rank == 0) {
            cout << "Testcase " << t+1 << ": Processes=" << size 
                 << ", Time=" << duration.count() << " ms" << endl;
        }
    }

    MPI_Finalize();
    return 0;
}