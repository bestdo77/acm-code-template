#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
vector<int> e[N];
int dp[N][2];
void dfs(int u,int fa){
    dp[u][0]=dp[u][1]=1;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0]=(dp[u][0]*(dp[v][0]+dp[v][1]))%mod;
        dp[u][1]=(dp[u][1]*dp[v][0])%mod;
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1);
    if(n==0) dp[1][0]=dp[1][1]=1;
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}