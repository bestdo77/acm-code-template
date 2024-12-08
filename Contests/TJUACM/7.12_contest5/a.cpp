#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long 
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
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	n=1e8;
	eulr();
    int t=1;
    int cnt1=0;
    int p=0;
    while(t--){
        int a=50,b=5;
        int cnt=0;
        cin>>a>>b;
        for(int i=1;i<=a;i++){
            bool flag=1;
            for(int j=1;j<=b;j++){
                if(i%prime[j]==0){
                    flag=0;break;
                }
            }
            if(flag) cnt++;
        }
        cout<<cnt<<endl;
        cnt1=cnt;
    }
    
	return 0;
}