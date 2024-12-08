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


vector <int> e[N];
int dfn[N],low[N],dfncnt=0;
int vis[N];
int ans[N],res=0;//ans[i]=1 -> 点i是割点

void Tarjan(int u,int fa){
    vis[u]=1;
    low[u]=dfn[u]=++dfncnt;
    int ccnt=0;
    int len=e[u].size();
    for (int i=0;i<len;i++){
        int v=e[u][i];
        if(v==fa)continue;
        if(!vis[v]){
            ccnt++;
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=u&&low[v]>=dfn[u]){
                ans[u]=1;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
    if(fa==u&&ccnt>=2){
        ans[u]=1;
    }
}


signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >>n>>m;
    for (int i=0;i<m;i++){
        int u,v;
        cin >>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if(!vis[i])Tarjan(i,i);
    }
    for (int i=1;i<=n;i++){
        if(ans[i])res++;
    }
    cout <<res<<endl;
    for (int i=1;i<=n;i++){
        if(ans[i])cout <<i<<" ";
    }
}