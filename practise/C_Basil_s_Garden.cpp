#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int h[N],dp[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int left=0;
        for(int i=1;i<=n;i++) cin>>h[i];
        dp[n]=0;
        for(int i=n-1;i>=1;i--){
            if(h[i]<=h[i+1]) dp[i]=h[i+1]-h[i]+1+dp[i+1];
            else dp[i]=max(0LL,dp[i+1]-(h[i]-h[i+1])+1);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]+h[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}