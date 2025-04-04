#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// #define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
struct edge{
    int v,w;
};
vector<edge> e[N];
int d[N],vis[N],n,m,s;//d[i]数组表示的是第i个点到目标点的最短距离
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=3*n;i++) d[i]=inf;
    for(int i=0;i<=3*n;i++) vis[i]=0;
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
void Atomatic_AC_machine(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v;
        e[u].push_back({v+n,1});
        e[u+n].push_back({v+2*n,1});
        e[u+2*n].push_back({v,1});
    }
    int s,t;cin>>s>>t;
    dijkstra(s);
    if(d[t]!=inf){
        cout<<d[t]/3<<endl;
    }else{
        cout<<-1<<endl;
    }
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}