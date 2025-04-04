#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=1e6+10;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,s;
bool vis[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=2*n;i++) d[i]=inf;
    for(int i=0;i<=2*n;i++) vis[i]=0;
    d[s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto [_,u]=q.top();q.pop();
        if(vis[u]) continue;
        vis[u]=1;//标记u已经入队
        for(auto &[v,w]:e[u]){
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
    int x;
    cin>>n>>m>>x;
     for(int i=1;i<=n;i++){
        e[i].push_back({i+n,x});
        e[i+n].push_back({i,x});
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back({v,1});
        e[v+n].push_back({u+n,1});
    }
    int ans1=inf;
    dijkstra(1);
    ans1=min({ans1,d[n],d[2*n]});
    cout<<ans1<<endl;
    return 0;
}