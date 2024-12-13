#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e5+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct STtable{
	int logg2[N];
	int dp[N][20];
	void init(int n){
		for(int i=2;i<=n;i++){
			logg2[i]=logg2[i>>1]+1;
		}
		for(int j=1;j<=logg2[n];j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				dp[i][j]=min(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
			}
		}
	}
	int query(int l,int r){
		int k=logg2[r-l+1];
		return min(dp[l][k],dp[r-(1<<k)+1][k]);
	}
}st;
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    memset(st.dp,0x3f,sizeof(st.dp));
    for(int i=1;i<=n;i++){
        cin>>st.dp[i][0];
    } 
    st.init(n);
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        cout<<st.query(l,r)<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}