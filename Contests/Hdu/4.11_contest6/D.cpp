#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;
const int MAX_N = 2e5 + 10;

i64 fact[MAX_N * 2];  // 预计算到2e5足够
i64 pow2[MAX_N * 2];
i64 inv_pow2[MAX_N * 2];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < 2*MAX_N; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    
    pow2[0] = 1;
    for (int i = 1; i < 2*MAX_N; ++i) {
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
    
    for (int i = 0; i < 2*MAX_N; ++i) {
        inv_pow2[i] = i == 0 ? 1 : inv_pow2[i-1] * 500000004LL % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;
    
    if (n == 1) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    
    i64 sum = 0, sum_sq = 0;
    for (auto x : a) {
        sum = (sum + x) % MOD;
        sum_sq = (sum_sq + x % MOD * x % MOD) % MOD;
    }
    
    i64 s = (sum * sum % MOD - sum_sq + MOD) % MOD;
    s = s * 500000004LL % MOD; 
    
    i64 inv_denominator = inv_pow2[n-1];
    i64 ways = fact[n] * fact[n-1] % MOD;
    ways = ways * inv_denominator % MOD;
    
    cout << s << " " << ways << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}