#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
double dp[N1][N1];
double p[N1];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]*(1-p[i]);
        for(int j=i;j>=1;j--){
            dp[i][j]=dp[i][j]+dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }    
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j>=1;j--){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }  
    double ans=0;
    for(int i=n/2+1;i<=n;i++){
        ans+=dp[n][i];
    }
    printf("%.10lf\n",ans);
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}