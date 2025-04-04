#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif
const int N=2e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int dp[2100][2100];
void init(int n){
   dp[1][1]=1;dp[1][0]=1;
   for (int i=2;i<=n;i++){
        dp[i][0]=1;
        for (int j=1;j<=i+1;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}
int C(int n,int m){
    if(n==0||m==0) return 1;
    else return dp[n][m];
}
int ans[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    int ins=n-k+1;
    int ans=0;
    init(max(n,k));
    for(int i=1;i<=k;i++){
        cout<<(C(n-k+1,i)*C(k-1,i-1))%mod<<endl;
    }
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}