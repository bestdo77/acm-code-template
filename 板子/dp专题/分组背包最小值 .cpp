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
    int t;cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=1;i<=n;i++){
            s[i]=4;
            for(int j=1;j<=s[i];j++){
                cin>>v[i][j];
                w[i][j]=j;
            }
        }
        for(int i=1;i<=c;i++) dp[i]=inf;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=c;j>=0;j--){
                for(int k=0;k<=s[i];k++){//k=0代表不取
                    if(j>=w[i][k]){
                        dp[j]=min(dp[j],v[i][k]+dp[j-k]);
                    }
                }
            }
            for(int i=1;i<=c;i++) cout<<dp[i]<<" ";
                cout<<endl;
        }
        cout<<dp[c]<<endl;
    }
    return 0;

}