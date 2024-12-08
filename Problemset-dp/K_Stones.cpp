#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int dp[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];   
    for(int i=0;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i>=a[j]&&dp[i-a[j]]==0) dp[i]=1;
        }   
    }
    for(int i=1;i<=100;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    if(dp[k]==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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