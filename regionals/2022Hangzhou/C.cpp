#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=3e3+10;
int w[N][N],v[N][N],dp[N][2],s[N],n,c;//dp表示体积为x的背包能装的最大价值
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=1;j<=s[i];j++){
            w[i][j]=j;
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
    for(int j=c;j>=0;j--){
            for(int k=0;k<=s[i];k++){//k=0代表不取
                if(j>=w[i][k]){
                    if(k==s[i]){
                        dp[j][1]=max(dp[j][1],v[i][k]+dp[j-w[i][k]][1]);
                        // dp[j][0]=max(dp[j][0],v[i][k]+dp[j-w[i][k]][0]);
                    }
                    else {
                        for(int p=1;p<w[i][k];p++){
                            dp[c][1]=max(dp[c][1],v[i][k]+dp[c-p][0]);
                        }
                    }
                }
            }
        }
        for(int j=k;j>=p[i];j--) f[j][0]=max(f[j][0],f[j-p[i]][0]+w[i][p[i]]);
    }
    int x=0;
    for(int i=1;i<=c;i++){
        x=max(dp[i][0],x);
    }
    cout<<max(x,dp[c][1])<<endl;
    return 0;
}