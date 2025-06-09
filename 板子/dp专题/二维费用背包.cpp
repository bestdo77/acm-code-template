#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=1e4+10;
int w1[N],w2[N],v[N],dp[N][N],n,c;//dp表示体积为x的背包能装的最大价值
#pragma GCC optimize(3,"Ofast","inline")
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,c1,c2;
    cin>>n>>c1>>c2;//注意清理的的是0-体积，不是0-个数
    for(int i=1;i<=n;i++) v[i]=1;
    for(int i=1;i<=n;i++) cin>>w1[i]>>w2[i];
        
    for (int i=1; i<=n; i++)   // 此行语句也常用 while(n--) 代替，其中的n为物品个数
        for (int j=c1; j>=w1[i]; j--)
            for (int k=c2; k>=w2[i]; k--) {
                dp[j][k]=max(dp[j][k],dp[j-w1[i]][k-w2[i]]+v[i]);
            }
    cout<<min(n,dp[c1][c2]+1)<<endl;
    return 0;
}