#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int weight[N];
int dp[N];
vector<int> G[N];
void dfs(int u,int fa){
    dp[u]=weight[u];
    for(auto v:G[u]){
        if(v!=fa){
            dfs(v,u);
        }
    }
    int mn=inf;
    for(auto v:G[u]){
        if(v!=fa){
            mn=min(mn,dp[v]);
        }
    }
    if(u==1) return;
    if(G[u].size()==1) mn=weight[u]; 
    if(dp[u]<=mn) dp[u]=(dp[u]+mn)/2;
    else dp[u]=mn;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=2;i<=n;i++){
        int u,v=i;
        cin>>u;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    int ans=inf;
    for(auto v:G[1]){
        ans=min(dp[v],ans);
    }
    cout<<ans+dp[1]<<endl;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}