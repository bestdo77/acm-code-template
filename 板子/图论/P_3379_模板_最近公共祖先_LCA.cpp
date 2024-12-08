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
int fa[N],dep[N],son[N],sz[N],top[N];
vector<int> G[N];
void dfs1(int u,int father){
    fa[u]=father,dep[u]=dep[father]+1,sz[u]=1;
    for(auto v:G[u]){
        if(v==father) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t){//t记录链头
    top[u]=t;
    if(!son[u]) return;//除根节点外，每个点都有重儿子
    dfs2(son[u],t);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u]) continue;//排除重儿子
        dfs2(v,v);//轻儿子是一个链的开始，开始修改链头
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
void solve(){
    int n,s,q;cin>>n>>q>>s;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(s,s);
    dfs2(s,s);
    for(int i=1;i<=q;i++){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
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