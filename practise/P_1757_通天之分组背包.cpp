#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int N=1e3+10;
int w[N][N],v[N][N],dp[N],s[N],n,c;//dp表示体积为x的背包能装的最大价值
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n;
    for(int i=1;i<=n;i++){
        int x,y,p;cin>>x>>y>>p;
        w[p][++s[p]]=x;
        v[p][s[p]]=y;
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=0;j--){
            for(int k=0;k<=s[i];k++){//k=0代表不取
                if(j>=w[i][k]){
                    dp[j]=max(dp[j],v[i][k]+dp[j-w[i][k]]);
                }
            }
        }
    }
    cout<<dp[c]<<endl;
    return 0;
}