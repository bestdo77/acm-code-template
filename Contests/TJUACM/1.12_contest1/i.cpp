#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}

map<int,int> rm;
int rev5;
int solve(int x){
    if(rm[x]) return rm[x];
    int ans=0;
    if(x%6==0) ans=(ans+rev5*solve(x/6)%mod)%mod;
    if(x%5==0) ans=(ans+rev5*solve(x/5)%mod)%mod;
    if(x%4==0) ans=(ans+rev5*solve(x/4)%mod)%mod;
    if(x%3==0) ans=(ans+rev5*solve(x/3)%mod)%mod;
    if(x%2==0) ans=(ans+rev5*solve(x/2)%mod)%mod;
    rm[x]=ans;
    return ans;
}
void Atomatic_AC_machine(){
    rev5=quickpow(5,mod-2);
    rm[1]=1;
    int n;cin>>n;
    cout<<solve(n)<<endl;
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