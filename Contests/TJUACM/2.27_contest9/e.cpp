#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int a[N];
int f[N],inv[N];
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
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int summax=0;
    int summin=0;
    init(200000);
    for(int i=1;i<=n;i++){
        if(i-1>=k-1){
            summax=(summax+(C(i-1,k-1)*a[i])%mod)%mod;
        }
        if(n-i>=k-1){
            summin=(summin+(C(n-i,k-1)*a[i])%mod)%mod;
        }
    }
    cout<<(summax-summin+mod)%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}