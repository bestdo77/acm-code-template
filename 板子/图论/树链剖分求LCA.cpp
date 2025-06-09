#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dep[N],fa[N],son[N],sz[N],top[N];
vector<int> e[N];
void dfs1(int u,int f){
    fa[u]=f,dep[u]=dep[f]+1,sz[u]=1;
    for(int v:e[u]){
        if(v==f) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs2(int u,int t){
    top[u]=t;
    if(!son[u]) return; //无重儿子
    dfs2(son[u],t);
    for(int v:e[u]){
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);//只有重儿子能递归下去
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
int main(){
    int n,m,s;cin>>n>>m>>s;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(s,0);
    dfs2(s,s);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}