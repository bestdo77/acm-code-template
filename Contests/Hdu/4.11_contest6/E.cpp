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
vector<int> e[N];
i64 sz[N],c[N],ans[N],n;//儿子贡献是平方
void dfs1(int u,int fa){
    sz[u]=1;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        c[u]+=sz[v]*sz[v];
    }


    for(auto v:e[u]){
        if(v==fa) continue;
        ans[u]+=sz[v]*((n-sz[v])*(n-sz[v])-(c[u]-sz[v]*sz[v]+(n-sz[u])*(n-sz[u])));
    }//子树儿子为根
    ans[u]+=(n-sz[u])*((sz[u])*(sz[u])-c[u]);//非子树儿子为根
    ans[u]+=n*n-c[u]-(n-sz[u])*(n-sz[u]);//自己为根
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
        sz[i]=c[i]=ans[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++){
        cout<<(ans[i]-n)/2+n<<" ";
    }
    cout<<endl;
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