#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505, MAX_M = 505;
bool blocked[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        memset(blocked, 0, sizeof(blocked));
        for (int i = 1; i <= N; ++i) {
            int R;
            cin >> R;
            for (int j = 0; j < R; ++j) {
                int pos;
                cin >> pos;
                blocked[i][pos] = true;
            }
        }
        memset(dist, 0x3f, sizeof(dist));
        queue<pair<int, int>> q;
        for (int i = 1; i <= N; ++i) {
            if (!blocked[i][1]) {
                dist[i][1] = 0;
                q.emplace(i, 1);
            }
        }
        int ans = -1;
        const int di[] = {1, -1, 0, 0};
        const int dj[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (j == M) {
                ans = dist[i][j] + 1;
                break;
            }
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
                if (blocked[ni][nj]) continue;
                if (dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}