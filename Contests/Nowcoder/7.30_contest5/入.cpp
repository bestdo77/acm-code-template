#include <bits/stdc++.h>
using namespace std;
bitset<51> vis,last,t[51];
vector<int> e[51];
int res=0,n,m;
void D(int u,int now,int ans){
    if(vis[now]) return;
    res=max(res,ans);
    bitset<51> tem=t[u]&vis;
    tem=tem^t[u];
    vis^=tem;
    for (int i=0;i<e[now].size();i++)D(now,e[now][i],ans+1);
    vis^=tem;
}
signed main (){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        t[u][v]=t[v][u]=1;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++) D(0,i,1);
    cout<<res;
}