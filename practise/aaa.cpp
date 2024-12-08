#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
const int mod = 998244353;
int fa[N];
int dep[N];
int sz[N];
int f[N];
int quickpow(int x,int y){
    int re=1;
    while(y){
        if(y&1) re=(re*x)%mod;
        x=(x*x)%mod,y/=2;
    }
    return re;
}
void init(int n){
    for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x){
    if(x!=f[x]) return f[x]=find(f[x]);
    return f[x];
}

void join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy) f[fy]=fx;
}
vector <int> e[N];
void dfs(int u,int father){
    sz[u] = 1;
    fa[u] = father,dep[u] = dep[father] + 1;
    //cout<<"now "<<u<<endl;
    for(int v : e[u]){
        if(v == father) continue;
        dfs(v,u);
    }
    //cout<<"now return "<<u<<endl;
    return;
}
int uu[N],vv[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    init(n);
    for(int i=1;i<n;i++){
        cin>>uu[i]>>vv[i];
    }
    for(int i = 1;i<n;i++){
        long long u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    //cout<<1<<endl;
    int ans = 1;
    for(int i = 1;i<n;i++){
        long long u,v;
        u=uu[i],v=vv[i];
        int fau=find(u),fav=find(v);
        int k1=sz[fau],k2=sz[fav];
        if(find(fa[fau]) == find(v)){
            sz[fav] += k1;
            sz[fau]=0;
            join(fav,fau);
            ans*=quickpow(k1,mod-2) * quickpow(k2,mod-2)%mod;
        }
        else if(find(fa[fav]) == find(u)){
            sz[fau] += k2;
            sz[fav]=0;
            join(fau,fav);
            ans*=quickpow(k1,mod-2) * quickpow(k2,mod-2)%mod;
        }
        else {
            ans = 0;
        }
        ans%=mod;
    }
    cout<<(long long)ans<<endl;
}
