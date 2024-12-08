#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[N];
int a[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    fill(dp+1,dp+1+n,inf);
    dp[1]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=max(i-k,1ll);j<=i-1;j++){
            dp[i]=min(dp[i],dp[j]+abs(a[i]-a[j]));
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;
    cout<<dp[n]<<endl;
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