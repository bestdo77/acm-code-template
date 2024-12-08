#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[110][110000];
int a[N],pre[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        pre[0]=1;
        for(int j=1;j<=k;j++){
            pre[j]=(dp[i-1][j]+pre[max(j-1,0ll)])%mod;
        }
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j]=1;
                continue;
            }
            if(j-a[i]<0){
                dp[i][j]+=pre[j];
            }else dp[i][j]=(pre[j]-pre[j-a[i]-1]+mod)%mod;
        }
    }
    cout<<dp[n][k]<<endl;
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