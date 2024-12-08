#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N][N],pre[N][N][N]

int main() {
    // 初始化原始数组 a
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
            }
        }
    }

    // 构建前缀和数组
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                // 计算前缀和
                long long sum = 0;
                if (i > 1) sum += pre[i - 1][j][k];
                if (j > 1) sum += pre[i][j - 1][k];
                if (k > 1) sum += pre[i][j][k - 1];
                if (i > 1 && j > 1) sum -= pre[i - 1][j - 1][k];
                if (i > 1 && k > 1) sum -= pre[i - 1][j][k - 1];
                if (j > 1 && k > 1) sum -= pre[i][j - 1][k - 1];
                if (i > 1 && j > 1 && k > 1) sum += pre[i - 1][j - 1][k - 1];
                pre[i][j][k] = sum + a[i][j][k];
            }
        }
    }

    // 查询示例
    return 0;
}