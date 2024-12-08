#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define inf 0x3f3f3f3f
const int mod=998244353;
int a[5100000];
int ans[5100000];
const int MAXN=1e3+10;
ll quickpow(ll x,ll y,ll mod)
{
	ll re=1;
	while(y!=0)
	{
		if(y%2==1) re=re*x%mod;
		
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re%mod;
}
int f[1000005],g[1000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=1,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int rev=quickpow(n,mod-2,mod);
    int tmp=rev,ans=0;
    for(int i=1;i<=n;i++){
        // cout<<tmp<<endl;
        ans=(ans+a[i]*tmp)%mod;
        tmp=rev*tmp%mod+tmp;
        tmp%=mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}