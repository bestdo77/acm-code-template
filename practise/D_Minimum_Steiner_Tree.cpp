#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int fat[N];
vector<int> aa;
int vis[N];
void dfs(int u,int fa){
    for(auto v:G[u]){
        if(v==fat[u]) continue;
        fat[v]=u;
        dfs(v,u);
    }
}
void solve(){
    vis[0]=1;
    int n,k;cin>>n>>k;
    // cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        // cout<<u<<" "<<v<<endl;
    }
    int x;
    for(int i=1;i<=k;i++){
        cin>>x;
        aa.push_back(x);
        vis[x]=1;
        // cout<<x<<endl;
    }
    dfs(x,0);
    // for(int i=0;i<aa.size();i++) cout<<aa[i]<<" ";
    // cout<<endl;
    for(int i=0;i<aa.size();i++){
        if(!vis[fat[aa[i]]]){
            aa.push_back(fat[aa[i]]);
            vis[fat[aa[i]]]=1;
        }
    }
    // for(int i=0;i<aa.size();i++) cout<<aa[i]<<" ";
    // cout<<endl;
    cout<<aa.size()<<endl;
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