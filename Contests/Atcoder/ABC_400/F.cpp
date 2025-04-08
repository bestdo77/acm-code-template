#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<i64> c(2*n+1),x(2*n+1);  
    vector<vector<i64>> dp(2*n+1,vector<i64>(2*n+1,0));//dp[l][r];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        c[i+n]=c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    i64 ans=infll;
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            if(len==1){
                dp[l][l]=x[c[l]]+1;
            }else{
                dp[l][r]=dp[l][r-1]+x[c[r]]+1;//直接加上
                for(int j=l;j<=r-1;j++){
                    if(c[j]==c[r]) dp[l][r]=min(dp[l][r],dp[l][j]+r-j+dp[j+1][r-1]);
                }
            }
            if(len==n){
                ans=min(dp[l][r],ans);
            }
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}