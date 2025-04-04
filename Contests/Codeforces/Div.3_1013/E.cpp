#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
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
const int MAXN=1e7+10;
bool isprime[MAXN];
int prime[MAXN],cnt;
i64 countprime[MAXN];
void eulr(int n){
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++){
		if(isprime[i]) prime[++cnt]=i;
        countprime[i]=cnt;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}
const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int n;cin>>n;
    i64 ans=0;
    for(int i=1;i<=n;i++){
        ans+=countprime[n/i];   
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    eulr(10000000);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}