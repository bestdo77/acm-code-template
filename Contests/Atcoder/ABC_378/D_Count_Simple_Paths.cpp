#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int n,m,k;
char mp[N1][N1];
int vis[N1][N1];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;
void dfs(int i,int j,int kk){
    if(i<1||i>n||j<1||j>m) return;
    if(vis[i][j]||mp[i][j]=='#') return;
    // cout<<i<<" "<<j<<" "<<kk<<endl;
    if(kk==k){
        ans++;
        return;
    }
    for(int t=0;t<4;t++){
        vis[i][j]=1;
        dfs(i+dx[t],j+dy[t],kk+1);
        vis[i][j]=0;
    }
}
void Atomatic_AC_machine(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!='#') dfs(i,j,0);
        }
    }
    cout<<ans<<endl;
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