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
vector<int> G[N];
int dp[N][2];
int vis[N];
void dfs(int u,int fa){
    dp[u][0]=0,dp[u][1]=weight[u];
    for(auto v:G[u]){
        if(v!=fa){
            dfs(v,u);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>weight[i];
    for(int i=2;i<=n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        vis[u]=1;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(!vis[i]) root=i;
    }
    dfs(root,0);
    cout<<max(dp[root][0],dp[root][1])<<endl;
    return;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}