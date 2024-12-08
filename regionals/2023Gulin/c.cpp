#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=4e5+10;
int d[60],pow2[N],rk;
void insert(int x){
	for(int i=30;i>=0;i--){
		if(x&(1<<i)){
			if(d[i]) x^=d[i];
			else{
				d[i]^=x;
				rk++;
				return;
			}
		}
	}
}
bool check(int x){
	for(int i=30;i>=0;i--){
		if(x*(1<<i)){
			if(d[i]) x^=d[i]; 
		}
	}
	return x==0;
}
vector<int> g[N];
int cnt[N];
void sol(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2*n;j+=i) g[j].push_back(i); 
	}
	for(int i=0;i<=2*n;i++){//枚举每个结果
		int cc=0;
		memset(d,0,sizeof(d));
		rk=0;
		for(auto fac:g[i]){
			if(cnt[fac]){
				insert(fac);
				cc+=cnt[fac];
			}
		}
		if(check(i)) ans=(ans+pow2[cc-rk])%mod;
	}
	cout<<ans-1<<endl;
	for(int i=0;i<=n;i++){
		cnt[i]=0;
	}
	for(int i=0;i<=2*n;i++){
		g[i].clear();
	}
}
signed main(){
	pow2[0]=1;
	for(int i=1;i<=2e5;i++){
		pow2[i]=(pow2[i-1]*2)%mod;
	}
	int T;cin>>T;while(T--)sol();
	return 0;
}