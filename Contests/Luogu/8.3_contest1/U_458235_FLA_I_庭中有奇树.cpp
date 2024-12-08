#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
//复杂度n*n+m
struct edge{
    int v,w;//边的另一个点和权值。
};
int d[N],vis[N],n,m,k,s,t;//d[i]数组表示的是第i个点到目标点的最短距离
vector<edge> e[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=n;i++) d[i]=inf;
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
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>s>>t;
    bool xxx=0;
    int minn=inf;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(v==t||u==t) minn=min(w,minn);
        if(u==s&&v==t||(v==s&&u==t)) xxx=1;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra(s);
    if(m==0){
        if(!xxx) cout<<min(d[t],k)<<endl;
        else cout<<min(d[t],minn+k)<<endl;
    }else{
        cout<<min(d[t],k)<<endl;
    }
    return 0;
}