#include <iostream>
using namespace std;
#define int long long
const int mod=1e9+7;
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
