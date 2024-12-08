#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
const int element=3;
// int a[N];
vector<int> G[N];
map<int,int> mp;
pii a[N1];
int p;
int dp[N1][N1];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    for(auto &it:mp){
        a[++p]={it.first,it.second};
    }
    for(int i=0;i<=p;i++){
        for(int j=0;j<=p;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=0;
    // cout<<p<<endl;
    for(int i=1;i<=p;i++){
        for(int j=0;j<=i;j++){
            if(j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j]=dp[i-1][j]+1;
            if(j+a[i].second<=p) dp[i][j]=min(dp[i-1][j+a[i].second],dp[i][j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    // for(int i=1;i<=p;i++){
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }
    int ans=inf;
    cout<<dp[p][0]<<endl;
    mp.clear();
    p=0;
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