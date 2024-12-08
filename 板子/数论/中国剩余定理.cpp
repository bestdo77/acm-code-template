#include <bits/stdc++.h>
#define N int(1e5+10)
using namespace std;
typedef long long ll;
ll a[20],b[20],t[20],k;
inline ll quickpow(ll x,ll y,ll mod){
	ll ret=1;
	while(y){
		if(y&1)(ret*=x)%=mod;
		(x*=x)%=mod;y>>=1;
	}
	return ret;
}
inline ll quickmul(ll x,ll y,ll m){
	while(x<0) x+=m;
	while(y<0) y+=m;
	if(x<y) swap(x,y);
	ll ret=0;
	while(y){
		if(y&1)(ret+=x)%=m;
		(x+=x)%=m,y>>=1;
	}
	return ret;
}

void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);y-=(a/b)*x;
}

ll CRT(){//中国剩余定理，给定一堆模数，和取模后的值，询问这个数的值。
	ll ans=0,lcm=1,x,y;
	for(int i=1;i<=k;i++){
		lcm*=b[i];
	}
	for(int i=1;i<=k;i++){
		t[i]=lcm/b[i];
		exgcd(t[i],b[i],x,y);
		x=(x%b[i]+b[i])%b[i];
		ans=(ans+quickmul(quickmul(t[i],a[i],lcm),x,lcm))%lcm;
	}
	return (ans+lcm)%lcm;
}

int main(){
	cin>>k;
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<=k;i++) cin>>b[i];
	cout<<CRT();
	return 0;
}