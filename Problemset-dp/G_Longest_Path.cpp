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
int f[N],vis[N];
int dfs(int u){
    if(e[u].size()==0||vis[u]) return f[u];
    vis[u]=1;
    for(auto v:e[u]){
        // cout<<u<<" "<<v<<endl;
       f[u]=max(f[u],dfs(v)+1);
    }
    return f[u];
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) ans=max(ans,dfs(i));
    }
    cout<<ans<<endl;
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