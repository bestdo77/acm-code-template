#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6;
const int inf = 0x3f3f3f3f3f3f3f3f;
struct card{
    int pi,v;
}a[N];
int dp[105][3050][150];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i].v>>a[i].pi;
    }
    for (int gg=0;gg<=n;gg++){
    for (int i=0;i<=3000;i++){
        for(int j=0;j<=105;j++){
            dp[gg][i][j]=-inf;
        }
    }
    }
    dp[0][1500][0]=0;
    for (int i=1;i<=n;i++){
        int v=a[i].v,pi=a[i].pi;
        for (int j=100;j<=2900;j++){
            for (int r=0;r<=105;r++){
                dp[i][j][r]=dp[i-1][j][r];
                if (dp[i-1][j-pi][r]!=inf)dp[i][j][r]=max(dp[i][j][r],dp[i-1][j-pi][r]+v);
                if (r!=0)if (dp[i-1][j-2*pi][r-1]!=inf)dp[i][j][r]=max(dp[i][j][r],dp[i-1][j-2*pi][r-1]+v);
                if (dp[i-1][j+pi][r]!=inf)dp[i][j][r]=max(dp[i][j][r],dp[i-1][j+pi][r]+v);
                if (r!=0)if (dp[i-1][j+2*pi][r-1]!=inf)dp[i][j][r]=max(dp[i][j][r],dp[i-1][j+2*pi][r-1]+v);
            }
        }
    }
    int ans=-inf;
    for (int i=0;i<=k;i++){
        ans=max(ans,dp[n][1500][i]);
    }
    cout <<ans<<endl;
}