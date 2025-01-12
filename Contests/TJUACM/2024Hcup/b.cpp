#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1ll<<31)-1;
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=4e3+10;
const int mod=1e9+7;
const int eps=2e3;
struct edge{
    int v,w;
};
int x,y,l,r,n,m,d[N1];
bool vis[N1];
vector<edge> e[N1];
priority_queue<pii,vector<pii>,greater<pii> pq;
void dijkstra(int s){
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;pq.push({0,s});
    while(pq.size()){
        pii tmp=pq.top();
        pq.pop();
        int u=tmp.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v;
            int w=ed.w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void Atomatic_AC_machine(){
    cin>>x>>y>>l>>r>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        int dis=abs(a-b);
        for(int i=l;i<=r-dis;i++){
            e[i+eps].push_back({i+dis+eps,c});
        }
        for(int i=l+dis;i<=r;i++){
            e[i+eps].push_back({i-dis+eps,c});
        }
    }
    int ans=inf;
    dijkstra(x-y+eps);
    ans=min(ans,d[m]);
    dijkstra(y-x+eps);
    ans=min(ans,d[m]);
    cout<<ans<<endl;
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