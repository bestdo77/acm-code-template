#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N = 1e6 + 10;
const int N1 = 1e3 + 10;
const int mod = 1e9 + 7;
string s;
int len;

// 计算 x 是 2 的多少次幂
int log2_floor(int x) {
    int res = 0;
    while (x > 1) {
        x >>= 1;
        res++;
    }
    return res;
}

char dfs(int x, int flag) {
    if (x <= len) {
        char sx = s[x];
        if (flag == -1) {
            if (sx >= 'a' && sx <= 'z') sx -= 'a' - 'A';
            else if (sx >= 'A' && sx <= 'Z') sx += 'a' - 'A';
        }
        return sx;
    } else {
        int duan = x / len;
        int log_duan = log2_floor(duan);
        int nx = x - (1LL << log_duan) * len;
        if (x == (1LL << log_duan) * len) {
            nx = x / 2;
        }
        return dfs(nx, -flag);
    }
}

void Atomatic_AC_machine() {
    cin >> s;
    len = s.size();
    s = " " + s;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << dfs(x, 1) << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        Atomatic_AC_machine();
    }
    return 0;
}