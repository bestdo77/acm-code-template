#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int N=1e3+10;
int w[N],v[N],dp[N],n,c;//dp表示体积为x的背包能装的最大价值
int path[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=0;i<=c;i++) dp[i]=0;//注意清理的的是0-体积，不是0-个数
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            for(int j=c;j>=w[i];j--){
                if(dp[j-w[i]]+v[i]>dp[j]){
                    dp[j]=dp[j-w[i]]+v[i];
                    path[i][j]=1;//这个物品在比前面所有物品优.
                }
            }
        }
        cout<<dp[c]<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++){
                cout<<path[i][j];
            }cout<<endl;
        }
        int i=n,j=c;
        while(i>0&&j>0){
            if(path[i][j]){
                cout<<i<<" ";
                j-=w[i];
            }
            i--;
        }
    }
    return 0;
}