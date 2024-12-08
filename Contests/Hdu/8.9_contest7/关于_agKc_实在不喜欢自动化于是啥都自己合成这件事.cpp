#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int out=1e9;
const int element=3;
int a[N];
struct edge{int v,w;};
vector<edge> G[N];
int typ[N];
int ans[N];
int dp[N];
int k;
void dfs(int x,int cntt,int fa){
    if(typ[x]==0){
        if(cntt>1e9) cntt=1e9;
        dp[fa]+=cntt*a[x];
        dp[x]=cntt*a[x];
        if(dp[x]>out) dp[x]=1e10;
        if(dp[fa]>out)  dp[fa]=1e10;
        // cout<<fa<<" "<<cntt<<" "<<dp[fa]<<endl;
        return;
    }
    if(typ[x]==1){
        for(auto it:G[x]){
            dfs(it.v,min((int)1e9,it.w*cntt),x);
        }
        dp[fa]+=dp[x];
        if(dp[fa]>1e9)  dp[fa]=1e10;
    }
}
void solve(){
    int n;cin>>n>>k;
    for(int i=1;i<=n;i++){
        int p;cin>>p;
        if(p){
            int l;cin>>l;
            for(int j=1;j<=l;j++){
                int x,y;cin>>x>>y;
                G[i].push_back({y,x});
            }
            typ[i]=1;
        }else{
            cin>>a[i];
        }
    }
    dfs(k,1,0);
    int maxx=0;
    int anss=0;
    for(auto it:G[k]){
        int v=it.v;
        anss+=dp[v];
        maxx=max(maxx,dp[v]);
    }
    if(typ[k]==0){
        cout<<a[k]<<endl;
    }else{
        if(anss-maxx<=out&&anss>0) cout<<anss-maxx<<endl;
        else cout<<"Impossible"<<endl;
    }
    for(int i=0;i<=n;i++){
        dp[i]=0;
        ans[i]=0;
        typ[i]=0;
        a[i]=0;
        G[i].clear();
    }
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