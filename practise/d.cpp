#include <iostream>
#include <queue>
// #incldue <algorithm>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N],dp[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=1;j<=i-1;j++){
            if(a[i]>a[j]){
                mx=max(mx,dp[j]);
            }
        }
        // cout<<i<<" "<<mx<<endl;
        dp[i]=mx+1;
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
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