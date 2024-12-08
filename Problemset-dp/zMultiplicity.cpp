#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[N];//长度为i的方案数
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> fac[n+1]{};
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=1;j<=sqrt(x);j++){
            if(x%j==0){
                if(j*j==x){
                    fac[i].push_back(j);
                    continue;
                }
                fac[i].push_back(x/j);
                fac[i].push_back(j);
            }
        }
        sort(fac[i].begin(),fac[i].end());
        reverse(fac[i].begin(),fac[i].end());
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(auto x:fac[i]){
            // cout<<x<<" ";
            if(dp[x-1]) dp[x]=(dp[x]+dp[x-1])%mod;
        }
        cout<<endl;
    }
    int sum=0;
    for(int i=1;i<=1e6;i++){
        sum=(sum+dp[i])%mod;
    }
    cout<<sum<<endl;
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