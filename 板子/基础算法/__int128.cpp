#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=5e6+10;
const int mod=998244353;
const int element=3;
int f[N],inv[N];
#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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
char buf[134217728];
const char* pin = buf;
inline unsigned ReadU() { for (; *pin < '0'; ++pin); unsigned ans = *pin ^ '0'; for (; *(++pin) >= '0'; ans = ans * 10 + *pin - '0'); return ans; }
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.read(buf, 134217728);
    int n=ReadU(),m=ReadU();
    init(m);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=ReadU(),y=ReadU();
        ans^=C(x,y);
    }
    printf("%ld\n",ans);
    return 0;
}