#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,cnt;
const int MAXN=1e8+10;
bool isprime[MAXN];
int prime[MAXN];
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	eulr();
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cout<<prime[x]<<endl;
	}
	return 0;
}