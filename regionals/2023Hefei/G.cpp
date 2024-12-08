#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
int n,m,k,id=1;
string s;
const int N=2e5+10;
int dp[N][6][2];
int pre[N];
bool check(int x){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j][0]=dp[i][j][1]=inf;
        }
    }
    dp[0][0][0]=0;
    int p=0;
    for(int i=1;i<=n;i++){
        if(i-x>=1&&s[i-x]=='0') p=i-x;
        for(int j=0;j<=5;j++){
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
            if(j>=1&&i>=x) dp[i][j][1]=min(dp[i][j][1],dp[p][j-1][0]+pre[i]-pre[p]);
        }
    }                 
    int cost=inf;
    cost=min(dp[n][k][1],dp[n][k][0]);
    return cost<=m;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0') pre[i]=pre[i-1]+1;
        else{
            pre[i]=pre[i-1];
        }
    }
    int l = -1, r = n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    if(l==0) cout<<-1<<endl;
    else cout<<l<<endl;
}