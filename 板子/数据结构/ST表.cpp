#include <bits/stdc++.h>
using namespace std;
const int N=110000;
#define endl "\n"
struct STtable{
	int logg2[N];
	pair<int,int> dp[N][20];
	void init(int n){
		for(int i=2;i<=n;i++){
			logg2[i]=logg2[i>>1]+1;
		}
		for(int j=1;j<=logg2[n];j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int qmax(int l,int r){
		int k=logg2[r-l+1];
		return max(dp[l][k],dp[r-(1<<k)+1][k]).first;
	}
	int qpos(int l,int r){
		int k=logg2[r-l+1];
		return max(dp[l][k],dp[r-(1<<k)+1][k]).second;
	}
}st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		st.dp[i][0].first=x;
		st.dp[i][0].second=i;
	}
	st.init(n);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cout<<st.qmax(l,r)<<endl;
	}
	return 0;
}