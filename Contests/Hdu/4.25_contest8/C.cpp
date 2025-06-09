#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> grid(N + 1, vector<int>(M + 1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> min_col_in_row(K + 1, vector<int>(N + 1, M + 1));
        for (int c = 1; c <= K; ++c) {
            for (int i = 1; i <= N; ++i) {
                min_col_in_row[c][i] = M + 1;
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int c = grid[i][j];
                if (j < min_col_in_row[c][i]) {
                    min_col_in_row[c][i] = j;
                }
            }
        }

        vector<vector<int>> pre_min(K + 1, vector<int>(N + 1, M + 1));
        for (int c = 1; c <= K; ++c) {
            pre_min[c][0] = M + 1;
            for (int x = 1; x <= N; ++x) {
                pre_min[c][x] = min(pre_min[c][x - 1], min_col_in_row[c][x]);
            }
        }

        long long ans = 0;
        for (int X = 1; X <= N; ++X) {
            bool valid = true;
            int maxY = 0;
            for (int c = 1; c <= K; ++c) {
                if (pre_min[c][X] == M + 1) {
                    valid = false;
                    break;
                }
                if (pre_min[c][X] > maxY) {
                    maxY = pre_min[c][X];
                }
            }
            if (!valid) continue;
            if (maxY > M) continue;
            int count = M - maxY + 1;
            if (count > 0) {
                ans += count;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}