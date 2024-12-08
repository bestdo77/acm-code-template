#include <bits/stdc++.h>

using namespace std;

#define int long long
using i32 = int32_t;
using vi = vector<int>;
const int inf = 1e18;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, sum = 0;
    cin >> n >> m;
    vector f(m + 1, vi(2, -inf));
    f[0][0] = 0;
    for (int i = 1, p; i <= n; i++) {
        cin >> p, sum = min(sum + p, m);
        vi w(p + 1);
        for (int j = 1; j <= p; j++) cin >> w[j];
        for (int j = m; j >= 0; j--) {
            if (j - p >= 0) {
                if (f[j - p][0] > -inf) f[j][0] = max(f[j][0], f[j - p][0] + w[p]);
                if (f[j - p][1] > -inf) f[j][1] = max(f[j][1], f[j - p][1] + w[p]);
            }
            for (int k = 1; k < p; k++)
                if (j - k >= 0 and f[j - k][0] > -inf) f[j][1] = max(f[j][1], f[j - k][0] + w[k]);
        }
    }
    cout << max( f[sum][0] , f[sum][1] );
    return 0;
}

