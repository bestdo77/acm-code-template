#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define double long double
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int dep[N];
double dp[N];
struct edge{int to,w;};
struct node{int cnt0,cnt1;double ans;} a[N],emp;
vector<edge> G[N];
void dfs1(int fa,int u){
    dep[u]=dep[fa]+1;
    for(auto it:G[u]){
        int v=it.to;
        int w=it.w;
        if(v==fa) continue;
        a[v]=a[u];
        if(w==0){
            a[v].cnt0++;
            a[v].ans=min(a[v].ans,((double)a[v].cnt0)/(double)(a[v].cnt1+a[v].cnt0));
        }else{
            a[v].cnt1++;
        }
        if(a[v].cnt0==0) a[v].ans=1;
        dfs1(u,v);
    }
}
void dfs2(int fa,int u){
    if(G[u].size()==1&&u!=1){
        dp[u]=a[u].ans;
        return;
    }
    for(auto it:G[u]){
        int v=it.to;
        if(v==fa) continue;
        dfs2(u,v);
    }
    if(dep[u]%2){
        dp[u]=0;
        for(auto it:G[u]){
            int v=it.to;
            if(v==fa) continue;
            dp[u]=max(dp[u],dp[v]);
        }
    }else{
        dp[u]=1;
        for(auto it:G[u]){
            int v=it.to;
            if(v==fa) continue;
            dp[u]=min(dp[u],dp[v]);
        }
    }
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        G[i].clear();
        dp[i]=0;
        a[i]=emp;
        dep[i]=0;
    }
    for(int i=1;i<=n-1;i++){
        int x,y,z;cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    dfs1(0,1);
    dfs2(0,1);
    cout<<setprecision(12)<<fixed<<dp[1]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}