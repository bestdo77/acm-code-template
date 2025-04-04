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
const int mod=1e9+7;
int n,st,en;
vector<int> e[N];
vector<int> ans;
int has[N];
void dfs1(int u,int fa){   
    for(auto v:e[u]){
        if(v==fa) continue;
        if(has[u]&&u!=st) has[v]=1;
        dfs1(v,u);
        if(has[v]) has[u]=1;
    }
}
void dfs(int u,int fa){
    bool flag=0;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
    if(!has[u]) ans.push_back(u);
}
void dfs2(int u,int fa){
    bool flag=0;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs2(v,u);
    }
    if(has[u]&&u!=st) ans.push_back(u);
}
void Atomatic_AC_machine(){
    cin>>n>>st>>en;
    for(int i=1;i<=n;i++){
        has[i]=0;
    }
    has[en]=1;
    ans.clear();
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(st,0);
    dfs(st,0);
    ans.push_back(st);
    dfs2(en,0);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
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