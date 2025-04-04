#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

constexpr int N = 200010;
int _ = 1;
int m[N];


void solve() {
    int n, res = 1;
    cin >> n;
    memset(m, 0, sizeof(int) * (n + 1));
    vector<vector<int>> adj(n + 1);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        m[u]++;
        m[v]++;
    }
    int cnt = 0, cntmx = 0;
    int mx = max_element(m + 1, m + n + 1) - m;
    for (int i = 1; i <= n; i++) cnt += m[i] == m[mx];
    for (auto i : adj[mx]) cntmx += m[i] == m[mx];
    // cout << mx << ' ' << cnt << ' ' << cntmx << endl;
    if (cnt - 1 == cntmx && cnt > 2) mx = max_element(m + mx + 1, m + n + 1) - m;
    // cout << mx << endl;
    if (m[mx] > 1) res += m[mx] - 1;
    for (auto i : adj[mx]) m[i]--;
    m[mx] = 0;

    cnt = 0, cntmx = 0;
    mx = max_element(m + 1, m + n + 1) - m;
    for (int i = 1; i <= n; i++) cnt += m[i] == m[mx];
    for (auto i : adj[mx]) cntmx += m[i] == m[mx];
    if (cnt - 1 == cntmx && cnt > 2) mx = max_element(m + mx + 1, m + n + 1) - m;
    res += m[mx] - 1;
    for (auto i : adj[mx]) m[i]--;
    m[mx] = 0;

    cout << res << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--) solve();
    return 0;
}

