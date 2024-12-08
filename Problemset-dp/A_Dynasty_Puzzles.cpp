#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[26][26];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        // cout<<s[0]<<" "<<s.back()<<endl;
        for(int j=0;j<26;j++){
            if(dp[j][s[0]-'a']) dp[j][s.back()-'a']=max(dp[j][s[0]-'a']+(int)s.length(),dp[j][s.back()-'a']);
        }
        dp[s[0]-'a'][s.back()-'a']=max((int)s.length(),dp[s[0]-'a'][s.back()-'a']);
    }
    // for(int i=0;i<26;i++){
    //     for(int j=0;j<26;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    int ans=0;
    for(int i=0;i<26;i++){
        ans=max(ans,dp[i][i]);
    }
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