#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[N1][N1];//use li,rj
void Atomatic_AC_machine(){
    string a,b,s;cin>>a>>b>>s;
    int n=a.size(),m=b.size();
    a=" "+a,b=" "+b;
    s=" "+s;
    int ans=inf;
    for(int i=0;i<=n;i++){
        if(i!=0) dp[i][0]=dp[i-1][0]+(s[i]!=a[i]);
        else dp[i][0]=(s[i]!=a[i]);
        for(int j=1;j<=m;j++){
            int p=i+j;
            if(i!=0) dp[i][j]=min(dp[i-1][j]+(s[p]!=a[i]),dp[i][j-1]+(s[p]!=b[j]));
            else dp[i][j]=dp[i][j-1]+(s[p]!=b[j]);
        }
    }
    cout<<dp[n][m]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}