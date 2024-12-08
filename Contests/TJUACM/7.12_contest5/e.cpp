#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
int prime[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
double last[20];
int dp[20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n1,k;cin>>n1>>k;
        __int128 n=n1;
        for(int i=1;i<=k;i++){
            dp[i]=n/prime[i];
            last[i]=n*1.0/prime[i]-n/prime[i];
        }
        //for(int i=1;i<=k;i++) cout<<last[i]<<endl;
        __int128 ans=0;
        ans=dp[1];
        double lastans=last[1];
        for(int i=2;i<=k;i++){
            ans=(ans+dp[i])-(int)((ans*dp[i]*1.0+ans*last[i]+lastans*dp[i]+lastans*last[i])/n);
            lastans=-(ans*dp[i]*1.0+ans*last[i]+lastans*dp[i]+lastans*last[i])/n-(int)((ans*dp[i]*1.0+ans*last[i]+lastans*dp[i]+lastans*last[i])/n);
            int ans1=ans;
          //  cout<<ans1<<endl;
        }
        int ans1=ans;
        cout<<n1-ans1<<endl;
    }
    return 0;
}