#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
int d[N1][N1];
struct edge{
    int u,v,w;
}e[N];
void Atomatic_AC_machine(){
    memset(d,0x3f,sizeof(d));
    int N,m;cin>>N>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        d[v][u]=d[u][v]=min(d[u][v],w);
        e[i]={u,v,w};
    }
    for(int i=1;i<=N;i++) d[i][i]=0;
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
    int q;cin>>q;
    for(int t=1;t<=q;t++){
        int ans=inf;
        int n;cin>>n;
        vector<int> cru(n+1,0);
        vector<int> p(n+1,0);
        iota(p.begin(),p.end(),0);
        for(int i=1;i<=n;i++) cin>>cru[i];
        print(cru);
        do{
           int ans1=inf;
           for(int i=0;i<(1<<n);i++){
                int ans2=0;
                int lst=1;
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        ans2+=d[lst][e[cru[p[j+1]]].u]+e[cru[p[j+1]]].w;
                        lst=e[cru[p[j+1]]].v;
                    }else{
                        ans2+=d[lst][e[cru[p[j+1]]].v]+e[cru[p[j+1]]].w;
                        lst=e[cru[p[j+1]]].u;
                    }
                }
                ans2+=d[lst][N];
                ans1=min(ans2,ans1);
           }
           ans=min(ans1,ans); 
        }while(next_permutation(p.begin()+1,p.end()));
        cout<<ans<<endl;
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