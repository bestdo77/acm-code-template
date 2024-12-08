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
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m;
bool vis[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=n;i++) d[i]=inf;
    for(int i=0;i<=n;i++) vis[i]=0;
    d[s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;//标记u已经入队
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<int> des;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        if(v==1) des.push_back(u);
        e[u].push_back({v,1});
    }
    dijkstra(1);
    int ans=inf;
    // bool flag=0
    for(auto it:des){
        // cout<<it<<endl;
        if(d[it]!=inf){
            ans=min(ans,d[it]+1);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<d[i]<<" ";
    // }cout<<endl;
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}