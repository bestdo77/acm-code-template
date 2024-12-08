#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=5e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct edge{
    int v,w;
};
int d[N];//构成tire树的数字
int trie[N*3][2],idx;
vector<edge> e[N];
void insert(int x){
    int p=0;
    for(int i=32;i>=0;i--){
        bool j=x&(1ll<<i);
        if(!trie[p][j]) trie[p][j]=++idx;   
        p=trie[p][j];
    }
}
int xormx(int x){
    int re=0;
    for(int i=32;i>=0;i--){
        int p=0;
        bool st=(x&(1ll<<i));
        if(trie[i][!st]){
            re+=(1ll<<i);
            p=trie[i][!st];
        }else{
            p=trie[i][st];
        }
    }
    return re;
}
void dfs(int u,int fa,int xorsum){
    d[u]=xorsum;
    for(auto ed:e[u]){
        int v=ed.v,w=ed.w;
        if(v==fa) continue;
        dfs(v,u,xorsum^w);
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,1,0);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<endl;
        insert(d[i]);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,xormx(d[i]));
    }
    cout<<mx<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}