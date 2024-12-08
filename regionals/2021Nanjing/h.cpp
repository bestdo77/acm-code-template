#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+10;
int dp[maxn][2];
int a[maxn],t[maxn];
vector <int> e[maxn];
struct st{
    int x = 0;
    int val = 0;
};
void dfs(int u,int father){
    st m,n;
    int maxx = 0;
    int sum = 0;
    for(int v:e[u]){
        if(v == father) continue;
        dfs(v,u);
        sum += dp[v][0] - a[v];
        maxx = max(maxx,a[v]);
        if(t[v] == 3){
            if(a[v] >= m.val){
                n = m;
                m = {v,a[v]};
            }
            else if(a[v] >= n.val){
                n = {v,a[v]};
            }
        }
        dp[u][1] += dp[v][0] - a[v];
    }
    dp[u][1] += a[u];
    dp[u][0] = sum + maxx;
    for(int v:e[u]){
        if(v == father) continue;
        if(dp[v][1] - (dp[v][0] - a[v]) <= 0) continue;
        if(v == m.x){
            dp[u][0] = max(dp[u][0],sum + n.val + dp[v][1] - (dp[v][0] - a[v]));

        }
        else{
            dp[u][0] = max(dp[u][0],sum + m.val + dp[v][1] - (dp[v][0] - a[v]));
        }
    }
    dp[u][0] += a[u];
    return;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) dp[i][0] = dp[i][1] = 0,e[i].clear();
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) cin>>t[i];
    for(int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    cout<<dp[1][0]<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}