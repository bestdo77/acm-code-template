#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
// #define int long long
#define endl "\n"
const int N=7000;
const int inf=1e9;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
long d[N][N],n,m,s;
int d1[N],cnt[N];
bool vis1[N],vis[N];
queue<int> q1;
bool spfa(int s){
    while(q1.size()) q1.pop();
    for(int i=0;i<=n;i++) vis1[i]=cnt[i]=0;
    for(int i=0;i<=n;i++) d1[i]=inf;
    d1[s]=0;vis1[s]=1;q1.push(s);
    while(q1.size()){
        int u=q1.front();q1.pop();vis1[u]=0;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d1[v]>d1[u]+w){
                d1[v]=d1[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n+1) return true;
                if(!vis1[v]) q1.push(v),vis1[v]=1;
            }
        }
    }
    return false;
}
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    while(q.size()) q.pop();
    for(int i=0;i<=n;i++) d[s][i]=inf;
    for(int i=0;i<=n;i++) vis[i]=0;
    d[s][s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;//标记u已经入队
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[s][v]>d[s][u]+w){
                d[s][v]=d[s][u]+w;
                q.push({d[s][v],v});
            }
        }
    }
}

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++){
        e[0].push_back({i,0});
    }
    if(spfa(0)){
        cout<<-1<<endl;
        return 0;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<d1[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=n;i++){
        for(auto &eu:e[i]){
            eu.w+=d1[i]-d1[eu.v];
        }
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<i<<" "<<j<<" "<<d[i][j]+d1[j]-d1[i]<<endl;
    //     }
    // }
    for(int i=1;i<=n;i++){
        long long ans=0;
        for(int j=1;j<=n;j++){
            if(d[i][j]==inf) ans+=j*inf;
            else ans+=j*(d[i][j]+d1[j]-d1[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}