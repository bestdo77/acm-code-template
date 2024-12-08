#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
string s[N];
vector<int> G[N];
const string t=" narek";
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    array<int,6> dp{};
    for(int i=1;i<=5;i++) dp[i]=-inf;
    dp[1]=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    for(int i=1;i<=n;i++){
        auto ndp=dp;
        for(int j=1;j<=5;j++){
            int res=dp[j];
            int y=j;
            for(int k=1;k<=m;k++){
                if(s[i][k]==t[y]){
                    y++;
                    if(y==6) res+=5,y=1;
                }
                else if(t.find(s[i][k])!=string::npos) res--;
                // cout<<res<<" "<<y<<endl;
            }
            // cout<<endl;
            ndp[y]=max(ndp[y],res);
        }
        dp=ndp;
        // for(int j=1;j<=5;j++){
        //     cout<<dp[j]<<" ";
        // }cout<<endl;
    }
    int res=0;
    for(int i=1;i<=5;i++){
        res=max(dp[i]-i+1,res);
    }
    cout<<res<<endl;
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