#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e7+10;
const int mod=1e9+7;
int dp[N],w[N/10],v[N/10];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n;
    cin>>c>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=0;i<=c;i++) dp[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=c;j++){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[c]<<endl;
    return 0;
}