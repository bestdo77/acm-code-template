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
vector<int> e[N];
int d[N],c[N],csz[N],sigc;
int ans=0;
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    for(auto v:e[u]){
        if(v!=fa){
            dfs(v,u);
            csz[u]+=csz[v];
        }
    }   
}
void dfs1(int u,int fa,int ans1){
    ans=min(ans,ans1);
    for(auto v:e[u]){
        if(v!=fa){
            dfs1(v,u,ans1+sigc-2*csz[v]);
        }
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>c[i],csz[i]=c[i],sigc+=c[i];
    d[0]=-1;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        ans+=d[i]*c[i];
    }
    dfs1(1,0,ans);
    cout<<ans<<endl;
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