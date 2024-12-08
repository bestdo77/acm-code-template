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
int dp[N][4];//1R,2S,3P
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        // for(int j=1;j<=3;j++) dp[i][j]=dp[i-1][j];
        if(s[i]=='R') dp[i][3]=max(dp[i-1][2],dp[i-1][1])+1,dp[i][1]=max(dp[i-1][3],dp[i-1][2]);
        if(s[i]=='S') dp[i][1]=max(dp[i-1][3],dp[i-1][2])+1,dp[i][2]=max(dp[i-1][1],dp[i-1][3]);
        if(s[i]=='P') dp[i][2]=max(dp[i-1][3],dp[i-1][1])+1,dp[i][3]=max(dp[i-1][2],dp[i-1][1]);
    }
    cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<endl;
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