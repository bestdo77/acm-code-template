#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N][N], pre[N][N][N];

int main() {
    // 初始化原始数组 a
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }

    // 构建前缀和数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                // 计算前缀和
                long long sum = 0;
                sum += pre[i - 1][j][k];
                sum += pre[i][j - 1][k];
                sum += pre[i][j][k - 1];
                sum -= pre[i - 1][j - 1][k];
                sum -= pre[i - 1][j][k - 1];
                sum -= pre[i][j - 1][k - 1];
                sum += pre[i - 1][j - 1][k - 1];
                pre[i][j][k] = sum + a[i][j][k];
            }
        }
    }

    int q;
    cin >> q;

    // 查询
    for (int i = 1; i <= q; ++i) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

        // 计算子区域的和
        long long result = pre[x2][y2][z2];

        // 减去边界以外的部分
        result -= pre[x1 - 1][y2][z2];
        result -= pre[x2][y1 - 1][z2];
        result -= pre[x2][y2][z1 - 1];
        result += pre[x1 - 1][y1 - 1][z2];
        result += pre[x1 - 1][y2][z1 - 1];
        result += pre[x2][y1 - 1][z1 - 1];
        result -= pre[x1 - 1][y1 - 1][z1 - 1];

        cout<<result<<endl;
    }

    return 0;
}