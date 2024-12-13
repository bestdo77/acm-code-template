#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int logg2[N];
struct STtable1{
	pair<int,int> dp[N][20];
	void init(int n){
		for(int j=1;j<=logg2[n];j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int qpos(int l,int r){
		int k=logg2[r-l+1];
		return max(dp[l][k],dp[r-(1<<k)+1][k]).second;
	}
    int qmax(int l,int r){
        int k=logg2[r-l+1];
		return max(dp[l][k],dp[r-(1<<k)+1][k]).first;
    }
}mx;
struct STtable2{
	pair<int,int> dp[N][20];
	void init(int n){
		for(int j=1;j<=logg2[n];j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int qpos(int l,int r){
		int k=logg2[r-l+1];
        return min(dp[l][k],dp[r-(1<<k)+1][k]).second;
	}
}mn;
int solve(int l,int r){
    if(l>=r) return 0;
    int p1=mx.qpos(l,r);
    int p2=mn.qpos(l,r);
    if(p1>p2) swap(p1,p2);
    return solve(l,p1)+1+solve(p2,r);
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mx.dp[i][0]=make_pair(x,i);
        mn.dp[i][0]=make_pair(x,i);
    }
    mx.init(n);
    mn.init(n);
    cout<<solve(1,n)<<endl;
    return;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    for(int i=2;i<=N;i++){
        logg2[i]=logg2[i>>1]+1;
    }
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}