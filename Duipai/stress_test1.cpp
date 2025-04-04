#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h> // 新增头文件，用于获取当前时间
using namespace std;
using namespace chrono;
int main() {
    int testCount = 0;
    auto start_time = steady_clock::now();
    auto start_time_sys = system_clock::now(); // 记录绝对系统时间

    // 打印时间戳
    time_t start_time_t = system_clock::to_time_t(start_time_sys);
    tm* start_time_info = localtime(&start_time_t);
    cout << "Program started at: " 
         << start_time_info->tm_year + 1900 << "-" 
         << start_time_info->tm_mon + 1 << "-" 
         << start_time_info->tm_mday << " " 
         << start_time_info->tm_hour << ":" 
         << start_time_info->tm_min << ":" 
         << start_time_info->tm_sec << endl << endl;
    while (testCount<500) {
        testCount++;
        system(".\\generator.exe > input.txt");  // 生成测试数据
        
        // 运行两个程序
        system(".\\code_a.exe < input.txt > output_a.txt");
        system(".\\code_b.exe < input.txt > output_b.txt");
        
        // 读取输出结果
        ifstream fa("output_a.txt"), fb("output_b.txt");
        int a, b;
        fa >> a;
        fb >> b;
        
        // 比较结果
        if (a != b) {
            cout << "Error found on test case #" << testCount << "!\n";
            cout << "Input:\n";
            system("type input.txt");
            cout << "\nOutput A: " << a << "\nOutput B: " << b << endl;
            
            // 保存错误数据
            ofstream log("error_log.txt");
            log << "Failed test case #" << testCount << "\n";
            log << "Input:\n";
            ifstream in("input.txt");
            log << in.rdbuf();
            log << "\nOutput A: " << a << "\nOutput B: " << b << endl;
            break;
        }
        cout << "Pass test case #" << testCount << "!\n";
    }
     auto end_time = steady_clock::now();
    auto end_time_sys = system_clock::now(); // 记录绝对系统时间

    // 计算运行时间
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    // 打印时间戳
    time_t end_time_t = system_clock::to_time_t(end_time_sys);
    tm* end_time_info = localtime(&end_time_t);
    cout << "\nProgram ended at: " 
         << end_time_info->tm_year + 1900 << "-" 
         << end_time_info->tm_mon + 1 << "-" 
         << end_time_info->tm_mday << " " 
         << end_time_info->tm_hour << ":" 
         << end_time_info->tm_min << ":" 
         << end_time_info->tm_sec << endl;

    // 最终状态报告
    cout << "Total runtime: " << duration.count() << " milliseconds" << endl;
    return 0;
}