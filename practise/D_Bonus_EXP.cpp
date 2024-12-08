#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int dp[2][N];//奇数ou
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(i%2){
            dp[1][i]=a[i]+dp[0][i-1];
        }else{
            dp[0][i]=2*a[i]+dp[1][i-1];
        }
    }
    for(int i=2;i<=n;i++){
        dp[0][i]=max({dp[1][i-1]+2*a[i],dp[0][i],dp[1][i-2]+2*a[i]});
        dp[1][i]=max({dp[0][i-1]+a[i],dp[1][i],dp[0][i-2]+a[i]});
    }
    cout<<max(dp[0][n],dp[1][n])<<endl;
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