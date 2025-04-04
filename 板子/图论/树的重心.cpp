#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
struct edge{
    int v,w;
};
vector<edge> e[N];
int d[N],c[N],csz[N],sigc;
int ans2[N];
int ans=0,ht=1;
void dfs(int u,int fa){
    for(auto [v,w]:e[u]){
        if(v!=fa){
            d[v]=d[u]+w;
            dfs(v,u);
            csz[u]+=csz[v];
        }
    }   
}
void dfs1(int u,int fa,int ans1){
    ans2[u]=ans1;
    for(auto [v,w]:e[u]){
        if(v!=fa){
            dfs1(v,u,ans1+w*(sigc-2*csz[v]));
        }
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) c[i]=1,csz[i]=1,sigc++;
    for(int i=1;i<n;i++){
        int u,v,w=1;cin>>u>>v;
        e[u].push_back(edge{v,w});
        e[v].push_back(edge{u,w});
    }
    d[1]=0;
    dfs(1,0);
    // for(int i=1;i<=n;i++){
    //     cout<<csz[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        ans+=d[i]*c[i];
    }
    dfs1(1,0,ans);
    for(int i=1;i<=n;i++){
        cout<<ans2[i]<<endl;
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