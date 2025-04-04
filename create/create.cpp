#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
using namespace filesystem;
int main() {
    const string targetFolder = "D:\\code\\Contests\\Codeforces\\Edu_177"; // 目标文件夹路径
    const string sourceFile = "D:\\code\\create\\start.cpp"; // 源文件路径
    const int n = 7; // 复制份数

    create_directory(targetFolder); // 创建文件夹

    for (int i = 0; i < n; ++i) {
        char letter = 'A' + i;
        path targetPath = targetFolder + "\\" + string(1, letter) + ".cpp";
        copy_file(sourceFile, targetPath); // 复制文件
    }
    return 0;
}

/*
g++ -std=c++17 create.cpp -o file_copier
.\file_copier.exe
*/