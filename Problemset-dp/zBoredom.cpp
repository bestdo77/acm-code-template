#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=400+10;
const int mod=167772161;
int dp[N1][N1][N1];
int dp1[N1][N1];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0][0]=1;
        for(int l=n;l>=1;l--){
            for(int r=k;r>=0;r--){
                if(r>=a[i]) dp[i][l][r]=(dp[i-1][l][r]+dp[i-1][l-1][r-a[i]])%mod;
                else dp[i][l][r]=dp[i-1][l][r];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=0;l<=n;l++){
            for(int r=0;r<=k;r++){
                dp1[l][r]=dp[n][l][r];
            }
        }
        int x=a[i];
        for(int l=1;l<=n;l++){
            for(int r=x;r<=k;r++){
                dp1[l][r]=(dp1[l][r]-dp1[l-1][r-x]+mod)%mod;
            }
        }
        for(int l=1;l<=n-1;l++){
            int sum=0;
            for(int r=max(1ll,k-x+1);r<=k;r++){
                sum+=dp1[l][r];
                sum%=mod;
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }
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