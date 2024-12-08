#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}
int s[N];
void solve(){
    int l,r,k;cin>>l>>r>>k;
    int x=9/k;
    // cout<<"11:"<<x<<endl;
    int p=quickpow(x+1,r)-quickpow(x+1,l);
    cout<<(p+mod)%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}