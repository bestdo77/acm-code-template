#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N1],pre[N1];
int dp[N1][N1];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if((n-len)%2) dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);//这个时候是别人取
            else dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
        }
    }
    cout<<dp[1][n]<<endl;
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