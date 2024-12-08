#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e3+10;
const int mod=1e9+7;
const int element=3;
int G[N][N];
bool vis[N][N];
int ans,n,m,k;
pii st,ed;
int dx[4]={0,0,1,-1};
void dfs(int x,int y){
    if(x<1||x>n||y<1||y>m||G[x][y]||vis[x][y]) return;
    if(ed==make_pair(x,y)){
        ans++;
        return;
    }
    vis[x][y]=1;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
    vis[x][y]=0; 
}
void solve(){
    cin>>n>>m>>k;
    cin>>st.first>>st.second>>ed.first>>ed.second;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        G[x][y]=1;
    }
    dfs(st.first,st.second);
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}