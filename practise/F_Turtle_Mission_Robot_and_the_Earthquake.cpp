#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N = 1e6 + 10;
const int N1 = 1e3 + 10;
const int mod = 1e9 + 7;
const int element = 3;

int a[N1][N1 << 1];

void Atomatic_AC_machine() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pii> q;
    vector<vector<int>> dist(n, vector<int>(m, -1)); // 正确使用 vector 初始化
    q.emplace(0, 0);
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); // C++17 结构化绑定
        q.pop();
        if (y < m - 1 && a[(x + 1) % n][y + 1] == 0 && dist[(x + 1) % n][y + 1] == -1) {
            dist[(x + 1) % n][y + 1] = dist[x][y] + 1;
            q.emplace((x + 1) % n, y + 1);
        }
        if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0 && dist[(x + 2) % n][y] == -1) {
            dist[(x + 2) % n][y] = dist[x][y] + 1;
            q.emplace((x + 2) % n, y);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int res = dist[i][m - 1];
        if (res != -1) { 
            if (res % n != (i + 1) % n) {
                res += ((i + 1) - (res % n) + n) % n;
            }
            if (ans == -1 || ans > res) {
                ans = res;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        Atomatic_AC_machine();
    }
    return 0;
}