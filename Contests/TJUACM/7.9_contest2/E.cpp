#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
int n,cnt;
const int MAXN=1e7+10;
bool isprime[MAXN];
int prime[MAXN];
int ans[MAXN];
void eulr(){
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++){
		if(isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(){
	n=1e7+10;
	eulr();
    int anst=0;
    ans[2]=0;
    for(int i=3;i<MAXN;i++){
            if(isprime[i]) anst+=2*i;
            else anst+=i;
        ans[i]=anst;
        }
    int t;scanf("%lld",&t);
    while(t--){
        int m;scanf("%lld",&m);
        
        
        printf("%lld\n",ans[m]);
    }
	
	return 0;
}