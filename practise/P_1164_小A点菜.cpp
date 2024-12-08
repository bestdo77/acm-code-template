#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N],dp[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,c;cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=c;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[c]<<endl;
    return 0;
}