#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct edge{
    int v,w;
};
int n,m,h;
vector<edge> e[N<<1];
int d1[N],dn[N];
void dijkstra(int s){
    vector<int> vis(n+1,0);
    priority_queue<pii,vector<pii>,greater<pii>> p;
    for(int i=1;i<=n;i++) dn[i]=inf;
    dn[s]=0;
    p.push({dn[s],s});
    while(p.size()){
        int u=p.top().second;
        p.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(dn[u]+w<dn[v]){
                dn[v]=dn[u]+w;
                p.push({dn[v],v});
            }
        }
    }
}
void Atomatic_AC_machine(){
    cin>>n>>m>>h;
    n*=2;
    vector<int> hor(n+1,0);
    for(int i=1;i<=h;i++){
        int x;cin>>x;
        hor[x]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        e[u+n/2].push_back({v+n/2,w/2});
        e[v+n/2].push_back({u+n/2,w/2});
        if(hor[u]) e[u].push_back({u+n/2,0});
        if(hor[v]) e[v].push_back({v+n/2,0});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++) d1[i]=dn[i];
    dijkstra(n/2);
    int ans=inf;
    for(int i=1;i<=n/2;i++){
        ans=min({ans,max(d1[i],dn[i]),max(d1[i],dn[i+n/2]),max(d1[i+n/2],dn[i]),max(d1[i+n/2],dn[i+n/2])});
    }
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
    for(int i=1;i<=n;i++) e[i].clear();
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}