#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int dp[N1][N1];
int p[N1][N1];
void init(int n){
   dp[1][1]=1;dp[1][0]=1;
   for (int i=2;i<=n;i++){
        dp[i][0]=1;
        for (int j=1;j<=i+1;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }           
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    init(n);
    int ans=0;
    // cout<<dp[0][100]<<endl;
    for(int j=1;j<=n/3;j++){
        if(dp[n-3*j+j-1][j-1]) ans=(ans+dp[n-3*j+j-1][j-1])%mod;
        else ans=(ans+1)%mod;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}