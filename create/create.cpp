#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

using namespace std;
using namespace filesystem;

int main() {
    try {
        const string targetFolder = "/home/sw7777/acm-code-template/Contests/Hdu/4.25_contest8";
        const string sourceFile = "/home/sw7777/acm-code-template/create/start.cpp";
        const int n = 7;

        create_directories(targetFolder);

        // 生成CPP和TXT文件
        for (int i = 0; i < n; ++i) {
            char letter = 'A' + i;
            
            // 生成CPP文件
            path cppPath = path(targetFolder) / (string(1, letter) + ".cpp");
            copy_file(sourceFile, cppPath, copy_options::overwrite_existing);

            // 生成空TXT文件
            path txtPath = path(targetFolder) / (string(1, letter) + ".txt");
            ofstream(txtPath).close(); // 创建空文件
        }

        // 生成唯一的run.sh（直接创建新文件）
        path runShPath = path(targetFolder) / "run.sh";
        path run1ShPath = path(targetFolder) / "run1.sh";
        copy_file("/home/sw7777/acm-code-template/create/run.sh", runShPath, copy_options::overwrite_existing);
        copy_file("/home/sw7777/acm-code-template/create/run1.sh", run1ShPath, copy_options::overwrite_existing);

        // 设置可执行权限
        permissions(runShPath,
                   perms::owner_all | perms::group_all | perms::others_all,
                   perm_options::add);
        permissions(run1ShPath,
                   perms::owner_all | perms::group_all | perms::others_all,
                   perm_options::add);

        cout << "生成完成：" << endl
             << "  * 7组题目文件（cpp+txt）" << endl
             << "  * 运行脚本: " << runShPath << endl
             << "  * 运行脚本: " << run1ShPath << endl;

    } catch (const filesystem_error& e) {
        cerr << "文件系统错误: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "错误: " << e.what() << endl;
        return 2;
    }
    
    return 0;
}