#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
vector<int> e1[N];//邻接表存图
vector<int> e2[N];
int d[N1][N1],n,s1,s2,m1,m2;
int hav1[N1][N1],hav2[N1][N1];
bool vis[N1][N1];
#define tii tuple<int,int,int>
priority_queue <tii,vector<tii>,greater<tii>> q;
void dijkstra(int s1,int s2){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                d[i][j]=inf;
            }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=0;
        }
    }
    d[s1][s2]=0;
    q.push({0,s1,s2});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        auto &[w,u1,u2]=t;
        if(vis[u1][u2]) continue;
        vis[u1][u2]=1;//标记u已经入队
        for(auto &v1:e1[u1]){
            for(auto &v2:e2[u2]){
                if(w+abs(v1-v2)<d[v1][v2]){
                    d[v1][v2]=w+abs(v1-v2);
                    q.push({d[v1][v2],v1,v2});
                }
            }
        }
    }
}
void Atomatic_AC_machine(){
    cin>>n>>s1>>s2;
    cin>>m1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            hav1[i][j]=hav2[i][j]=0;
        }
    }
    for(int i=1;i<=m1;i++){
        int u,v;cin>>u>>v;
        e1[u].push_back(v);
        e1[v].push_back(u);
        hav1[u][v]=hav1[v][u]=1;
    }
    cin>>m2;
    for(int i=1;i<=m2;i++){
        int u,v;cin>>u>>v;
        e2[u].push_back(v);
        e2[v].push_back(u);
        hav2[u][v]=hav2[v][u]=1;
    }
    dijkstra(s1,s2);
    vector<int> vis1(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis1[i]|=(hav1[i][j]&&hav2[i][j]);
        }
    }
    int ans=inf;
    for(int i=1;i<=n;i++){
        if(vis1[i]) ans=min(d[i][i],ans);
    }
    if(ans!=inf) cout<<ans<<endl; 
    else cout<<-1<<endl;
    for(int i=1;i<=n;i++){
        e1[i].clear();
        e2[i].clear();
    }
}
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}