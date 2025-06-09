#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int n, k;
    cin >> n >> k;
    
    // 特判：允许全元音的情况
    if(k >= n){
        i64 ans = 1;
        for(int i=0; i<n; i++) ans = ans * 26 % mod;
        cout << ans << endl;
        return;
    }
    
    vector<i64> prev(k+1, 0);
    prev[0] = 21;  // 第一个字符是辅音
    if(k >= 1) prev[1] = 5;  // 第一个字符是元音
    
    i64 sum = accumulate(prev.begin(), prev.end(), 0LL) % mod;
    
    for(int i=2; i<=n; i++){
        vector<i64> cur(k+1, 0);
        // 选辅音的情况
        cur[0] = sum * 21 % mod;
        
        // 选元音的情况
        for(int m=1; m<=k; m++){
            if(m-1 >= 0 && m-1 <= k-1)
                cur[m] = prev[m-1] * 5 % mod;
        }
        
        // 更新总和
        sum = accumulate(cur.begin(), cur.end(), 0LL) % mod;
        swap(prev,cur);
    }
    
    cout << sum << endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}