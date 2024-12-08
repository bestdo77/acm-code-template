#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;

vector <int > e[maxn];

int dep[maxn];//存深度
int fa[maxn][20]; //n logn + 1
//向上跳2i层的祖先结点，0是哨兵

//打表
void dfs(int u,int father){
    dep[u] =dep[father] + 1;
    fa[u][0] = father;
    for(int i = 1;i <= 19;i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }

    for(auto v : e[u]){
        if(v != father) dfs(v ,u);
    }
}

int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    //先跳到同一层
    for(int i=19;i >= 0;i--){
        if(dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    }
    if(u == v) return v;
    //再跳转到lca的下一层
    for(int i=19 ;i >= 0;i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int main(){
    int n,q,r;
    cin>>n>>q>>r;

    for(int i = 1;i < n;i++){
        int u,v;
        cin>> u>> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(r,0);
    for(int i=1;i <= q;i++){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;;
    }
    
}