#include <windows.h>
DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    
    return 0;
}

int main() {
    HANDLE hThread = CreateThread(
        NULL,                   // 安全属性
        0,                      // 栈大小
        ThreadFunc,             // 线程函数
        NULL,                   // 参数
        0,                      // 创建标志
        NULL                    // 线程ID
    );
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    return 0;
}
