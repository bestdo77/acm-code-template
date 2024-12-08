#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
//#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;


int a[N];
vector <int> e[N];
int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;  // 结点 i 所在 SCC 的编号;SCC总数
int sz[N];       // 强连通 i 的大小
vector <int> e2[N];
int a2[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
    for (int i = 0;i<e[u].size();i++) {
        const int &v = e[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        while (s[tp] != u) {
            scc[s[tp]] = sc;
            sz[sc]++;
            in_stack[s[tp]] = 0;
            --tp;
        }
        scc[s[tp]] = sc;
        sz[sc]++;
        in_stack[s[tp]] = 0;
        --tp;
    }
}
int DP[N];
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    for (int i=1;i<=m;i++){
        int u,v;
        cin >>u>>v;
        e[u].push_back(v);
    }
    for (int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    
    //缩点操作
    for (int i=1;i<=n;i++){
        a2[scc[i]]+=a[i];
    }
    for (int i=1;i<=n;i++){
        for (auto v:e[i]){
            if(scc[i]!=scc[v]){
                e2[scc[i]].push_back(scc[v]);
            }
        }
    }


    for (int i=1;i<=sc;i++){
        DP[i]=a2[i];
        for (auto v:e2[i]){
            if(v!=i){
                DP[i]=max(DP[v]+a2[i],DP[i]);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=sc;i++){
        ans=max(DP[i],ans);
    }
    cout <<ans<<endl;
}