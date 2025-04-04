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

struct edge{
    int v;
    char w;
};
char a[N1][N1];
vector<edge> e[N];//邻接表存图
vector<edge> e1[N];
int d[N1][N1],n,s1,s2,m1,m2;
int hav1[N1][N1],hav2[N1][N1];
bool vis[N1][N1];
#define tii tuple<int,int,int>
priority_queue <tii,vector<tii>,greater<tii>> q;
void dijkstra(){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=0;
        }
    }
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        auto &[w,u1,u2]=t;
        if(vis[u1][u2]) continue;
        vis[u1][u2]=1;//标记u已经入队
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][u1]!='-'&&a[i][u1]==a[u2][j]){
                    if(d[i][j]>d[u1][u2]+2){
                        d[i][j]=d[u1][u2]+2;
                        q.push({d[i][j],i,j});
                    } 
                }
            }
        }
    }
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                d[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char w;cin>>w;
            a[i][j]=w;
        }
    }
    
    for(int i=1;i<=n;i++){
        d[i][i]=0;
        q.push({d[i][i],i,i});
        for(int j=1;j<=n;j++){
            // if(i==j) continue;
            if(a[i][j]!='-'){
                if(i!=j)d[i][j]=1;
                q.push({1,i,j});
            }
        }
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(d[i][j]==inf?-1:d[i][j])<<" ";
        }
        cout<<endl;
    }
}
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}