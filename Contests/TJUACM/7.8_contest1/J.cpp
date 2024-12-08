#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int MAXN=1e6+10;
const int mod=1e9+7;
int dp[MAXN][3];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    if(s[0]=='1'&&s.length()==1){
        cout<<0<<endl;
        return 0;
    }
    s=" "+s;
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<s.length();i++){
        if(s[i]=='0'){//dp[i][0]表示后面没有雷，dp[i][1]表示后面有雷，dp[i][2]表示当前是雷。
            dp[i][0]=dp[i-1][0];
        }else if(s[i]=='1'){
            dp[i][0]=dp[i-1][2];
            dp[i][1]=dp[i-1][0];
        }else if(s[i]=='2'){
            dp[i][1]=dp[i-1][2];
        }else if(s[i]=='*'){
            dp[i][2]+=dp[i-1][1];
            dp[i][2]+=dp[i-1][2];
        }else{
            dp[i][0]=dp[i-1][0]+dp[i-1][2];
            dp[i][1]=dp[i-1][0]+dp[i-1][2];
            dp[i][2]=dp[i-1][1]+dp[i-1][2];
        }
    	dp[i][0]%=mod;
        dp[i][1]%=mod;
        dp[i][2]%=mod;
    }
    
    cout<<(dp[s.length()-1][0]+dp[s.length()-1][2])%mod<<endl;
    return 0;
}