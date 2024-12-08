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
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,k,s;
bool vis[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=n*(k+1);i++) d[i]=inf;
    d[s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    int st,ed;cin>>st>>ed;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        for(int i=1;i<=k;i++){
            e[u+i*n].push_back({v+i*n,w});
            e[v+i*n].push_back({u+i*n,w});
            //这里注意建上一条边
            e[u+i*n-n].push_back({v+i*n,0});
            e[v+i*n-n].push_back({u+i*n,0});
        }
    }
    dijkstra(st);
    int ans=inf;
    for(int i=0;i<=k;i++){
        ans=min(ans,d[i*n+ed]);
    }
    cout<<ans<<endl;
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