#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int rel[30][30];
int dp[(1<<22)];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>rel[i][j];
        }
    }
    dp[0]=1;
    for(int i=1;i<(1<<n);i++){
        int cnt=__builtin_popcount(i);
        // cout<<i<<" "<<cnt<<endl;
        for(int j=0;j<n;j++){
            if(((1<<j)&i)&&(rel[cnt][j+1])){
                dp[i]=(dp[i]+dp[i^(1<<j)])%mod;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<bitset<10>(i)<<" "<<dp[i]<<endl;
    // }
    cout<<dp[(1<<n)-1]<<endl;
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