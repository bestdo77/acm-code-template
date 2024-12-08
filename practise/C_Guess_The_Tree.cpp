#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N1][N1];
vector<int> G[N];
int query(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int res;cin>>res;
    // if(res==-1) while(1);
    return res;
}
int ans[N1];
void dfs(int x,int y){
    if(ans[x]&&ans[y]) return;
    if(a[x][y]) return;
    a[x][y]=query(x,y);
    if(a[x][y]==x){
        ans[y]=x;
        return;
    }
    if(a[x][y]==y){
        ans[x]=y;
        return;
    }
    dfs(x,a[x][y]);
    dfs(a[x][y],y);
}
void solve(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        dfs(1,i);
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        if(ans[i]){
            cout<<ans[i]<<" "<<i<<" ";
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) ans[i]=0;
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}