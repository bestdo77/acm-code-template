#include <bits/stdc++.h>
using namespace std;
#define int ull
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=5e6+10;
const int mod=998244353;
const int element=3;
int f[N],inv[N];
#define ull unsigned long long 
#define ui128 __uint128_t
struct Barrett{
    ull d;ui128 m;
    void init(ull _d){
        d=_d,m=(((ui128)(1)<<64)/d);
    }
}mod;
ull operator %(ull a,Barrett mod){
    ull w=(mod.m*a)>>64;w=a-w*mod.d;
    if(w>=mod.d)w-=mod.d;return w;
}
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}
void init(int maxnum){
    f[0]=1;
    for(int i=1;i<=maxnum;++i) f[i]=f[i-1]*i%mod;
    for(int i=0;i<=maxnum;i++) inv[i]=quickpow(f[i],mod-2);
}
int C(int n,int m){
    if(m<0||m>n) return 0;
    return f[n]*inv[m]%mod*inv[n-m]%mod;
}
vector<array<int,element>> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    int ans=0;
    init(m);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        ans^=C(x,y);
    }
    return 0;
}