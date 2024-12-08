#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+9;
int quickpow(int x,int y){
    int re=1;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
const int N=1e7+10;
int dp[N];
signed main(){
    int m,k;
    cin>>m>>k;
    int ans=m,leaves=1;
    dp[1]=1;
    for(int i=1;i<k;i++){
        leaves=(leaves+m-1)%mod;
        dp[i+1]=(dp[i]+m*quickpow(leaves,mod-2))%mod;
        ans=(ans+m*dp[i+1])%mod;
    }
    cout<<ans<<endl;
}