#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <sstream>
using namespace std;
using namespace chrono;

struct TestResult {
    int test_id;
    int output_a;
    int output_b;
};

template <typename T, size_t Capacity>
class LockFreeQueue {
    T buffer[Capacity];
    atomic<size_t> head{0};
    atomic<size_t> tail{0};
public:
    bool push(const T& item) {
        size_t curr_tail = tail.load(memory_order_relaxed);
        size_t next_tail = (curr_tail + 1) % Capacity;
        
        if(next_tail == head.load(memory_order_acquire)) 
            return false;
        
        buffer[curr_tail] = item;
        tail.store(next_tail, memory_order_release);
        return true;
    }

    bool pop(T& item) {
        size_t curr_head = head.load(memory_order_relaxed);
        if(curr_head == tail.load(memory_order_acquire))
            return false;
        
        item = buffer[curr_head];
        head.store((curr_head + 1) % Capacity, memory_order_release);
        return true;
    }
};

LockFreeQueue<TestResult, 8192> resultQueue;
atomic<bool> errorFound{false};
atomic<int> testCounter{1};

void producer_thread() {
    while(!errorFound) {
        const int test_id = testCounter.fetch_add(1);
        
        if(test_id > 500) {
            testCounter--;
            break;
        }

        // 为每个测试生成唯一文件名
        stringstream ss;
        ss << "input_" << test_id << ".txt";
        const string input_file = ss.str();
        
        // 生成测试用例
        system((".\\generator.exe > " + input_file).c_str());
        
        // 执行测试
        const string output_a = "output_a_" + to_string(test_id) + ".txt";
        const string output_b = "output_b_" + to_string(test_id) + ".txt";
        system((".\\code_a.exe < " + input_file + " > " + output_a).c_str());
        system((".\\code_b.exe < " + input_file + " > " + output_b).c_str());

        // 读取结果
        TestResult res{test_id};
        ifstream(output_a) >> res.output_a;
        ifstream(output_b) >> res.output_b;
        
        while(!resultQueue.push(res) && !errorFound) {
            this_thread::yield();
        }
    }
}

void consumer_thread() {
    TestResult res;
    while(!errorFound) {
        if(resultQueue.pop(res)) {
            if(res.output_a != res.output_b) {
                // 原子操作确保只处理第一个错误
                bool expected = false;
                if(errorFound.compare_exchange_strong(expected, true)) {
                    // 读取文件内容
                    auto read_file = [](const string& filename) {
                        ifstream file(filename);
                        return string((istreambuf_iterator<char>(file)),
                                    istreambuf_iterator<char>());
                    };
                    stringstream ss;
                    ss << "input_" << res.test_id << ".txt";
                    const string input_file = ss.str();
                    // 输出错误信息到标准错误
                    const string output_a = "output_a_" + to_string(res.test_id) + ".txt";
                    const string output_b = "output_b_" + to_string(res.test_id) + ".txt";
                    cerr << "-------------------------" << endl;
                    cerr << "Failed test case #" << res.test_id << endl;
                    cerr << "-------------------------" << endl;
                    cerr << "Input file: " << input_file << endl;
                    cerr << read_file(input_file) << endl;
                    cerr << "-------------------------" << endl;
                    cerr << "Code A output: " << output_a << endl;
                    cerr << read_file(output_a) << endl;
                    cerr << "-------------------------" << endl;
                    cerr << "Code B output: " << output_b << endl;
                    cerr << read_file(output_b) << endl;
                    cerr << "-------------------------" << endl;
                }
            }
        } else {
            if(testCounter > 500) break;
            this_thread::yield();
        }
    }
}


int main() {
    constexpr int producer_num = 24;
    constexpr int consumer_num = 24;

    vector<thread> producers;
    vector<thread> consumers;
    
    auto start = high_resolution_clock::now();

    // Start workers
    for(int i = 0; i < producer_num; ++i)
        producers.emplace_back(producer_thread);
    for(int i = 0; i < consumer_num; ++i)
        consumers.emplace_back(consumer_thread);

    // Wait for completion
    for(auto& t : producers) t.join();
    for(auto& t : consumers) t.join();

    // Performance metric
    auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
    cout << duration.count() << endl;

    return errorFound ? 1 : 0;
}
