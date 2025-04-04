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
const i64 mod=998244853;
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    vector<i64> dp(m,0),a(n,0),ac(n,0),wa(n,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>ac[i];//对的概率
        wa[i]=(1-ac[i]+mod)%mod;
    }
    for(int j=0;j<n;j++){
        vector<i64> ndp(m,0);
        for(int i=0;i<m;i++){   
            ndp[(i+a[j])%m]=(ndp[(i+a[j])%m]+dp[i]*ac[j]%mod)%mod;
            ndp[i]=(ndp[i]+dp[i]*wa[j]%mod)%mod;
        }
        dp=ndp;
    }  
    cout<<dp[0]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}