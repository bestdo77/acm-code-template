#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<int> minp,primes;
int sg[N];
void sleve(int n){
	minp.assign(n+1,0);
	primes.clear();
	for(int i=2;i<=n;i++){
		if(minp[i]==0){
			primes.push_back(i);
			minp[i]=i;
		}
		for(auto p:primes){
			if(i*p>n) break;
			minp[i*p]=p;
			if(p==minp[i]) break;
		}

	}
}
void solve(){
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		ans^=sg[a];
		// cout<<a<<" "<<sg[a]<<endl;
	}
	if(ans!=0) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
int main(){
	int t;cin>>t;
	sleve((int)1e7);
	for(int i=0;i<primes.size();i++){
		sg[primes[i]]=i+1;
	}
	sg[1]=1;
	sg[2]=0;
	for(int i=3;i<=1e7;i++){
		sg[i]=sg[minp[i]];
	}
	while(t--){
		solve();
	}

}