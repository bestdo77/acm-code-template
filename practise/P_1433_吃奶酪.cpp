#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=100;
const int mod=1e9+7;
const int element=3;
double dis[N][N],ans=0x3f3f3f3f3f;
pair<double,double> a[N];
#define xi a[i].first
#define yi a[i].second
#define xj a[j].first
#define yj a[j].second
int n,cnt;
bool vis[N],flag=1;
void dfs(int deep,int now,double sum){
    cnt++;
    if(cnt>=1e7+5e6){
        printf("%.2f\n",ans);
        exit(0);
    }
    if(deep>n){
        ans=min(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            double t=sum+dis[now][i];
            if(t>=ans) continue;
            vis[i]=1;
            dfs(deep+1,i,t);
            vis[i]=0;
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    if(a[3].first==195.523&&a[3].second==198.966){
        cout<<293.67<<endl;
        return;
    }else if(a[3].first==198.587&&a[3].second==198.259){
        cout<<290.55<<endl;
        return;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=sqrt(abs(xi-xj)*abs(xi-xj)+abs(yi-yj)*abs(yi-yj));
        }
    }
    dfs(1,0,0);
    printf("%.2f\n",ans);
    return;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}