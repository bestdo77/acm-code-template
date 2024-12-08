#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=3e3+10;
const int mod=1e9+7;
string s;
int n,m;
int cost[26];
int dp[N1][N1];
void Atomatic_AC_machine(){
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        char ch;
        int del,add;
        cin>>ch>>del>>add;
        cost[ch-'a']=min(del,add);
    }
    for(int len=1;len<=m;len++){
        for(int l=1;l+len-1<=m;l++){
            int r=l+len-1;
            if(len==1){
                dp[l][r]=0;
            }else{
                if(s[l]!=s[r]) dp[l][r]=min(dp[l+1][r]+cost[s[l]-'a'],dp[l][r-1]+cost[s[r]-'a']);
                else{
                    dp[l][r]=dp[l+1][r-1];
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<endl;
    //     }
    // }
    cout<<dp[1][m]<<endl;
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