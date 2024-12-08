#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x80000000
int a[5100000];
const int mod=998244353;
const int maxn=5e5+10;
int dp1[maxn][2],dp2[maxn][2];
    int ans[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            dp1[i][0]=dp1[i][1]=x;
        }
        for(int i=0;i<n;i++){
            int x;cin>>x;
            dp2[i][0]=dp2[i][1]=x;
        }

        int m=1;
        while(m<n-1) m=(m<<1);
        for(int i=0;i<=19;i++){
            for(int j=m-1;j>=0;j--){
                if((!(j&(1<<i)))&&j<=n-1&&(j^(1<<i))<=n-1){
                    dp1[j][0]=min(dp1[j][0],dp1[j^(1<<i)][0]);
                    dp1[j][1]=max(dp1[j][1],dp1[j^(1<<i)][1]);
                    dp2[j][0]=min(dp2[j][0],dp2[j^(1<<i)][0]);
                    dp2[j][1]=max(dp2[j][1],dp2[j^(1<<i)][1]);
                } 
            }
        }
        ans[n]=-inf;
        int pr=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=max(max(dp1[i][0]*dp2[i][0],dp1[i][0]*dp2[i][1]),max(dp1[i][1]*dp2[i][0],dp1[i][1]*dp2[i][1]));
            ans[i]=max(ans[i],ans[i+1]);
            pr=(pr+ans[i])%mod;
        }
        cout<<(pr%mod+mod)%mod<<endl;
    }
    return 0;
}