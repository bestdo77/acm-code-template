#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
int dp[N];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    int ans=0;
    for(int i=1;i<=n;i++){
        int p=a[i-1]+k+1;//查上一个
        int q=a[i]-k;
        if(a[i]-a[i-1]>k) dp[i]=0;
        // cout<<p<<" "<<q<<" "<<lower_bound(a,a+1+n,q)-a<<" "<<lower_bound(a+1,a+n+1,p)-a-i+1<<endl;
        else dp[i]=lower_bound(a+1,a+n+1,p)-a-i;
        // dp[lower_bound(a,a+1+n,q)-a]+=dp[i];
    }
    // for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    // cout<<endl;
    for(int i=n;i>=1;i--) if(i+dp[i]+1<=n) dp[i]+=dp[i+dp[i]+1];
    for(int i=1;i<=n;i++) ans+=dp[i];
    // for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<ans<<endl;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}