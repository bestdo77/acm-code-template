#include <bits/stdc++.h>
using namespace std;
const int N=110000;
struct STtable{
	int logg2[N];
	int dp[N][20];
	void init(int n){
		for(int i=2;i<=n;i++){
			logg2[i]=logg2[i>>1]+1;
		}
		for(int j=1;j<=logg2[n];j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
			}
		}
	}
	int query(int l,int r){
		int k=logg2[r-l+1];
		return max(dp[l][k],dp[r-(1<<k)+1][k]);
	}
}st;
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x=read();
		st.dp[i][0]=x;
	}
	st.init(n);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cout<<st.query(l,r)<<endl;
	}
	return 0;
}