#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=3e3+10;
const int mod=1e9+7;
int dp[N1][N1];
void Atomatic_AC_machine(){
    string s,t;
    cin>>s>>t;
    int ls=s.length(),tl=t.length();
    s=" "+s,t=" "+t;
    for(int i=1;i<=ls;i++){
        for(int j=1;j<=tl;j++){
            if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int len=dp[ls][tl];
    // cout<<len<<endl;
    int i=ls,j=tl;
    while(len&&i>0&&j>0){
        if(s[i]==t[j]){
            ans.push_back(s[i]);
            i--,j--;
            len--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
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