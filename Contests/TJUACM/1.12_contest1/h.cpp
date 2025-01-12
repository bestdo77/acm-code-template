#include <iostream>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
const int MAXN=1e6+10;
bool isprime[MAXN];
int prime[MAXN];
void eulr(){
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<MAXN;j++){
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
    int ans=0;
    eulr();
    for(int i=3;i<=cnt;i++){
        for(int j=2;j<i;j++){
            int c=prime[i]*prime[i],b=prime[j];
            if(c*b>n) break;
            int a=(int)sqrt((1.0*n/(1.0*c*b)));
            // cout<<a<<endl;
            ans+=upper_bound(prime+1,prime+1+j-1,a)-prime-1;
        }
    }
    cout<<ans<<endl;
	return 0;
}