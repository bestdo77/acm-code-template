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
const int mod=998244353;
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    int ans=1;
    vector<int> lay(100,0);
    int x;cin>>x;
    for(int i=1;i<=k;i++){
        int y;cin>>y;
        int t=x;
        int cnt=0;
        while(t!=y){
            t=(t+1)/2;
            y=(y+1)/2;
            cnt++;
        }
        lay[cnt]++;
    }
    for(int i=1;i<=99;i++){
        int pow2=quickpow(2,i-1);
        ans=(ans*(1-lay[i]*quickpow(pow2,mod-2)%mod))%mod;;
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}   
signed main(){
    int size(256<<20);  // 256M
  __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    exit(0);
    return 0;

}
