#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(), x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 10;
const int N1 = 5e3 + 10;
const i64 mod = 998244353;
i64 a[N];
i64 pre[N];
i64 powk[N][11]; // powk[x][j] = pre[x]^j, x from 0 to n
i64 ppre[11][N]; // ppre[j][i] = sum_{x=1 to i} pre[x]^j
int C[N1][N1];   // C(n, k)

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        if (i == 0) continue;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Compute prefix sums pre[0..n], where pre[0] = 0
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = (pre[i - 1] + a[i]) % mod;
    }

    // Precompute powk[x][j] = pre[x]^j for x in 0..n and j in 0..k
    for (int x = 0; x <= n; ++x) {
        powk[x][0] = 1;
        for (int j = 1; j <= k; ++j) {
            if (x == 0) {
                powk[x][j] = 0; // pre[0] is 0, so 0^j = 0 for j > 0
            } else {
                powk[x][j] = powk[x][j - 1] * pre[x] % mod;
            }
        }
    }

    // Precompute ppre[j][i] = sum_{x=1 to i} pre[x]^j for j in 0..k
    for (int j = 0; j <= k; ++j) {
        ppre[j][0] = 0;
        for (int i = 1; i <= n; ++i) {
            ppre[j][i] = (ppre[j][i - 1] + powk[i][j]) % mod;
        }
    }

    // Initialize combination numbers
    init(k);

    i64 ans = 0;
    for (int i = 0; i <= k; ++i) {
        i64 comb = C[k][i];
        i64 sign = (i % 2 == 0) ? 1 : -1;

        i64 total = 0;
        for (int l = 1; l <= n; ++l) {
            // pre[l-1]^i
            i64 a_pow = powk[l - 1][i];
            // sum_{r=l}^n pre[r]^(k-i)
            i64 sum_r = (ppre[k - i][n] - ppre[k - i][l - 1] + mod) % mod;
            total = (total + a_pow * sum_r % mod) % mod;
        }

        i64 contribution = comb * total % mod;
        if (sign == 1) {
            ans = (ans + contribution) % mod;
        } else {
            ans = (ans - contribution + mod) % mod;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}