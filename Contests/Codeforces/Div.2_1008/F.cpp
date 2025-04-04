#include <iostream>
#include <vector>
#include <thread>
using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols, int init = 0) 
        : data_(rows, vector<int>(cols, init)) {}

    vector<int>& operator[](int row) { return data_[row]; }

    int rows() { return data_.size(); }
    int cols() { return data_.empty() ? 0 : data_[0].size(); }

    void print(){
        for(auto vec : data_) {
            for(auto x : vec) {
                cout<< x << " ";
            }
            cout << endl;
        }
    }
private:
    vector<vector<int>> data_;
};

void multiply_block(Matrix& A, Matrix& B, Matrix& C, int start_row, int end_row) {
    for (int i = start_row; i < end_row; ++i) {
        for (int j = 0; j < B.cols(); ++j) {
            C[i][j] = 0;
            for (int k = 0; k < A.cols(); ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

Matrix matrix_mul(Matrix& A, Matrix& B, int threadCount) {
    Matrix C(A.rows(), B.cols());
    vector<thread> threads;
    int rows_per_thread = A.rows() / threadCount;

    for (int t = 0; t < threadCount; ++t) {
        int start_row = t * rows_per_thread;
        int end_row = (t == threadCount - 1) ? A.rows() : start_row + rows_per_thread;

        threads.emplace_back([&A, &B, &C, start_row, end_row]() {
            multiply_block(A, B, C, start_row, end_row);
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    return C;
}

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    int threadCount = stoul(argv[1]);
    int testcase = stoul(argv[2]);

    for(int t = 1; t <= testcase; ++t) {
        int N = stoul(argv[t*3]);
        int K = stoul(argv[t*3+1]);
        int M = stoul(argv[t*3+2]);

        cerr<< N << " " <<  K << " " << M <<endl;
        Matrix A(N, K);
        Matrix B(K, M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) {
                A[i][j] = i + j;
            }
        }
        for(int i = 0; i < K; ++i){
            for(int j = 0; j < M; ++j){
                B[i][j] = i - j;
            }
        }
        Matrix C = matrix_mul(A, B, threadCount);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "cost: " << duration.count() << " milisecond" << std::endl;
    return 0;
}
/*
    input:
    8 3 5 7 13 3 4 5 2 2 2
*/