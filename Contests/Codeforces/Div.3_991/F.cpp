#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int dp[210000][20];
int logg2[210000];
void Atomatic_AC_machine(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    int id=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]) id=0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=abs(a[i]-a[i-1]);
    }
	
	int k=logg2[n];
	for(int j=1;j<=logg2[n];j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
        l++;
		int k=logg2[r-l+1];
		if(!id&&l<=r) cout<<__gcd(dp[l][k],dp[r-(1<<k)+1][k])<<" ";
        else cout<<"0 "; 
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=2;i<=200010;i++){
		logg2[i]=logg2[i>>1]+1;
	}
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}