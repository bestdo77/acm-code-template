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
struct edge{
    int v,w,w1;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,s,d1[N];
int t0,t1,t2,t3,t4;
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
            int v=ed.v,w=ed.w,w1=ed.w1;
            if(d[u]+w<=t4){
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    q.push({d[v],v});
                }
            }else{
                if(d[v]>d[u]+w1){
                    d[v]=d[u]+w1;
                    q.push({d[v],v});
                }
            }
        }
    }
}
void dijkstra1(int s){
    while(q.size()) q.pop();
    for(int i=0;i<=n;i++) d1[i]=inf;
    for(int i=0;i<=n;i++) vis[i]=0;
    d1[s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;//标记u已经入队
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w,w1=ed.w1;
            int tx=d1[v];
            int ty=d1[u]+w;
            if(tx>ty){
                d1[v]=ty;
                q.push({d1[v],v});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    cin>>t0>>t1>>t2;
    t3=t0-t1;
    t4=t0-t2;
    for(int i=1;i<=m;i++){
        int u,v,w,w1;cin>>u>>v>>w>>w1;
        // cout<<u<<" "<<v<<" "<<w<<" "<<w1<<endl;
        e[u].push_back({v,w,w1});
        e[v].push_back({u,w,w1});
    }
    dijkstra(n);
    // int ans1=d[1];
    dijkstra1(1);
    int ans=inf;
    // for(int i=1;i<=n;i++){
    //     cout<<d1[i]<<" "<<d[i]<<endl;
    // }
    for(int i=1;i<=n;i++){
        if(d1[i]>t1) continue;
        if(d[i]>=t3){
            ans=min(ans,d1[i]+d[i]);
        }else{
            ans=min(ans,d1[i]+t3);
        }
    }
    if(d[1]<t3) ans=min(ans,d[1]);
    if(ans>t0) cout<<-1<<endl;
    else cout<<t0-ans<<endl;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}