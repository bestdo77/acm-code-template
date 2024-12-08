#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int N=1e3+10;
int w[N],v[N],dp[N],n,c;//c为背包容量
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        for(int i=0;i<=c;i++) dp[i]=0;
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            for(int j=c;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        } 
    }
    return 0;
}