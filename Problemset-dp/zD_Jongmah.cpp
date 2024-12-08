#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int cnt[N];
int dp[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=cnt[i];j+=3){
            dp[i]=max(j/2+dp[i-1]+max({cnt[i]-j,dp[i-1],dp[i-2]})){
                
            }
        }
    }
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