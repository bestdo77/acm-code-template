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
    int v,w1,w2;
};
i64 ans[N];
i64 sum=0;
vector<edge> e[N];
bool hav[N];
int st,ed;
void dfs1(int u,int fa){
    for(auto &[v,w1,w2]:e[u]){
        if(v==fa) continue;
        dfs1(v,u);
        if(hav[v]) hav[u]=1;
        if(!hav[v]) ans[u]+=max(0ll,w1+w2+ans[v]);
    }
}
void dfs2(int u,int fa){
    sum+=ans[u];
    for(auto &[v,w1,w2]:e[u]){
        if(v==fa) continue;
        if(hav[v]){
            sum+=w1;
            dfs2(v,u);
        }
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    sum=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
        ans[i]=hav[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        e[u].push_back({v,w1,w2});
        e[v].push_back({u,w2,w1});
    }
    cin>>st>>ed;
    hav[ed]=1;
    dfs1(st,0);
    dfs2(st,0);
    // for(int i=1;i<=n;i++){
    //     cout<<hav[i]<<" ";
    // }
    // cout<<endl;
    
    // for(int i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    cout<<sum<<endl;
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