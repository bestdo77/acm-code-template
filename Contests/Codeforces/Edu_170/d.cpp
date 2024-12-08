#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[5050][5050],pass1[5050][5050],pass2[5050][5050];//第一维正，第二维负
int a[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int jia=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) ++jia;
        else if(a[i]>0){
            pass1[jia][a[i]]++;
        }else{
            pass2[jia][abs(a[i])]++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            pass1[i][j]+=pass1[i][j-1];
            pass2[i][j]+=pass2[i][j-1];
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(i+j>m) break;
            if(i>=1&&j>=1) dp[i][j]=max(dp[i-1][j],dp[i][j-1])+pass1[i+j][i]+pass2[i+j][j];
            else if(i==0&&j) dp[i][j]=dp[i][j-1]+pass1[i+j][i]+pass2[i+j][j];
            else if(j==0&&i) dp[i][j]=dp[i-1][j]+pass1[i+j][i]+pass2[i+j][j];
            if(i+j==m) ans=max(ans,dp[i][j]);
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
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