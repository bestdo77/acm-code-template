#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
int P,Q;
int n,a,b,p,q;
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
int rev(int x){
    return quickpow(x,mod-2);
}
int dp[N1][N1][2];
void Atomatic_AC_machine(){
    cin>>n>>a>>b>>p>>q;
    for(int i=1;i<=n;i++){
        dp[n][i][0]=dp[n][i][1]=1;
    }
    for(int i=n-1;i>=a;i--){
        for(int j=n-1;j>=b;j--){
            for(int k=1;k<=p;k++){
                dp[i][j][0]=(dp[i][j][0]+(dp[min(i+k,n)][j][1]*rev(p)%mod))%mod;
            }
            for(int k=1;k<=q;k++){
                dp[i][j][1]=(dp[i][j][1]+(dp[i][min(j+k,n)][0]*rev(q))%mod)%mod;
            }
        }
    }
    cout<<dp[a][b][0]<<endl;
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