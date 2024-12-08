v#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int mod;
#define ll long long
int dp[5010][5010];
int dp2[5010][5010];
ll quickpow(ll x,ll y,ll mod)
{
	ll re=1;
	while(y!=0)
	{
		if(y%2==1) re=re*x%mod;
		
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m>>mod;
    // for(long long i=2;i<=n;i++){
    //  	inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    //     cout<<inv[i]<<endl;
    //  }
    int ans=0;
    int ou=quickpow(2,m-1,mod);
   // cout <<operate(2,1)<<endl;
   //for (int i=0;i<=n;i++)cout <<inv[i]<<' ';
   cout <<endl;
   dp[1][1]=1;dp[1][2]=1;
   for (int i=2;i<=5001;i++){
    for (int j=1;j<=i+1;j++){
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
    }
   }
    for(int i=n;i>0;i--){
        ans+=(((dp[n][n-i+1]%mod)*quickpow(ou,n-i,mod))%mod*quickpow((quickpow(2,i,mod)-1),m-1,mod));
        ans%=mod;
    }
    for(int i=n-m+1;i>=0;i--){
        int aa=1;
        for(int j=1;j<=n-i;j++){
            (aa*=j)%=mod;
        }
        ans-=((aa*dp[m-1][n-i+1])%mod*quickpow(quickpow(2,n-i,mod)-1,m-n+i-1,mod))%mod;
        (ans+=mod)%=mod;
    }
    cout <<ans<<endl;
    return 0;
}