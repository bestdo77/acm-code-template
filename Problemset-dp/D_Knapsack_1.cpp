#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[N];
int v[N],w[N];
void Atomatic_AC_machine(){
    int n,c;cin>>n>>c;
    for(int i=1;i<=5000;i++){
        dp[i]=inf;
    }
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=v[i];j--){
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[c]<<endl;
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