#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct edge{
    int v,w;
};
vector<edge> e[N];
int d[N],n,m,s,vis[N];
void dijkstra(int s){
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({d[s],s});
    while(q.size()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto it:e[u]){
            int w=it.w,v=it.v;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void Atomatic_AC_machine(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}