#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,s;
bool vis[N];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=n*m;i++) d[i]=inf;
    for(int i=0;i<=n*m;i++) vis[i]=0;
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
char g[N1][N1];
int id(int x,int y){
    return m*(x-1)+y;
}
void Atomatic_AC_machine(){ 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    int a,b,c,D;cin>>a>>b>>c>>D;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j+1<=m){
                if(g[i][j+1]=='#'){
                    e[id(i,j)].push_back({id(i,j+1),1});
                }
                else{
                    e[id(i,j)].push_back({id(i,j+1),0});
                } 
            }
            if(j-1>=1){
                if(g[i][j-1]=='#'){
                    e[id(i,j)].push_back({id(i,j-1),1});
                }else{
                    e[id(i,j)].push_back({id(i,j-1),0});
                }
            }
            if(j+2<=m){
                e[id(i,j)].push_back({id(i,j+2),1});
            }
            if(j-2>=1){
                e[id(i,j)].push_back({id(i,j-2),1});
            }
            if(i+1<=n){
                if(g[i+1][j]=='#'){
                    e[id(i,j)].push_back({id(i+1,j),1});
                }else{
                    e[id(i,j)].push_back({id(i+1,j),0});
                }
            }
            if(i-1>=1){
                if(g[i-1][j]=='#'){
                    e[id(i,j)].push_back({id(i-1,j),1});
                }else{
                    e[id(i,j)].push_back({id(i-1,j),0});
                }
            }

            if(i+2<=n){
                e[id(i,j)].push_back({id(i+2,j),1});
            }
            if(i-2>=1){
                e[id(i,j)].push_back({id(i-2,j),1});
            }
        }
    }
    dijkstra(id(a,b));
    cout<<d[id(c,D)]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}