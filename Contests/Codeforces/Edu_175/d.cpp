#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=998244353;
vector<int> e[N];
int d[N],cntd[N],sz[N];
int pred[N],sufd[N];
int mxd=0;
void dfs1(int u,int fa){
    d[u]=d[fa]+1;
    cntd[d[u]]++;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
int F[N];
int ans[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        sz[i]=1;
        cntd[i]=0;
        d[i]=0;
        e[i].clear();
    }
    
    for(int i=2;i<=n;i++){
        int u;cin>>u;
        F[i]=u;
        e[u].push_back(i);
        e[i].push_back(u);
    }
    dfs1(1,0);
    mxd=*max_element(d+1,d+1+n);
    int mul=1;
    int ans=1;
    for(int i=2;i<=mxd;i++){
        ans=(ans+mul*cntd[i]%mod)%mod;
        mul=(mul*(cntd[i]-1))%mod;
    }
    // pa(sufd,mxd);
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}