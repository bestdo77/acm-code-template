#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,s;
bool vis[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=4*n*m;i++) d[i]=inf;
    for(int i=0;i<=4*n*m;i++) vis[i]=0;
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
//1-n向右，n+1-2n向下，2n+1-3n向左，向上
int cov(int i,int j){
    return (i-1)*m+j;
}
void Atomatic_AC_machine(){
    cin>>n>>m;
    for(int i=0;i<=4*n*m;i++){
        e[i].clear();
    }
    vector<vector<int>> a(n+1,vector<int>(m+1,0)),dd(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dd[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int id=cov(i,j);
            e[id].push_back({id+n*m,dd[i][j]});
            e[id].push_back({id+2*n*m,2*dd[i][j]});
            e[id].push_back({id+3*n*m,dd[i][j]});
            e[id+n*m].push_back({id,dd[i][j]});
            e[id+n*m].push_back({id+2*n*m,dd[i][j]});
            e[id+n*m].push_back({id+3*n*m,2*dd[i][j]});
            e[id+2*n*m].push_back({id,2*dd[i][j]});
            e[id+2*n*m].push_back({id+n*m,dd[i][j]});
            e[id+2*n*m].push_back({id+3*n*m,dd[i][j]});
            e[id+3*n*m].push_back({id,dd[i][j]});
            e[id+3*n*m].push_back({id+n*m,2*dd[i][j]});
            e[id+3*n*m].push_back({id+2*n*m,dd[i][j]});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int id=cov(i,j);
            if(j+1<=m) e[id].push_back({id+1,a[i][j+1]});
            if(i+1<=n) e[id+n*m].push_back({id+n*m+m,a[i+1][j]});
            if(j-1>=1) e[id+2*n*m].push_back({id+2*n*m-1,a[i][j-1]});
            if(i-1>=1) e[id+3*n*m].push_back({id+3*n*m-m,a[i-1][j]});
        }
    }
    e[0].push_back({1,a[1][1]});
    dijkstra(0);
    cout<<d[2*n*m]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}