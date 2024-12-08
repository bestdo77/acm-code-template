#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5 + 10;

int fa[maxn],dep[maxn],son[maxn],sz[maxn];
//父亲，深度，重儿子，子树的结点总数
int top[maxn];
//所在重链的顶点

vector <int > e[maxn];

void dfs1(int u,int father)//搞fa，dep，son
{
    fa[u] = father,dep[u] = dep[father] + 1,sz[u] = 1;
    for(int v : e[u]){
        if(v == father) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;//更新重儿子
    }
}

void dfs2(int u,int t)//参数为结点、所在重链顶点，搞top
{
    top[u] = t;//记录链头
    if(!son[u]) return;//无重儿子返回
    dfs2(son[u],t);//搜重儿子
    for(int v : e[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);//搜轻儿子，注意轻儿子的链头就是自己，不能和重儿子混淆
    }
}

int lca(int u,int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,r;
    cin>>n>>q>>r;

    for(int i = 1;i < n;i++){
        int u,v;
        cin>> u>> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(r,0);
    dfs2(r,r);
    for(int i=1;i <= q;i++){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;;
    }
}