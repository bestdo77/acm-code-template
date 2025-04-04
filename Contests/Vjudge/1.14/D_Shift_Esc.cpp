#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void print(vector<int> a){
    for(int i=1;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int a[N1][N1];
void Atomatic_AC_machine(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    vector<int> dp(m+1,inf),cost(m+1,0);
    for(int p=0;p<m;p++){
        vector<int> pre(m+1,0);
        for(int i=1;i<=m;i++){
            pre[i]=pre[i-1]+a[1][(i+p-1)%m+1];
        }
        for(int i=1;i<=m;i++){
            dp[i]=min(dp[i],pre[i]+p*k);
        }
    }
    // print(dp);
    for(int i=2;i<=n;i++){
        vector<int> dp1(m+1,inf);
        for(int p=0;p<m;p++){
            // vector<int> pre(m,0);
            // for(int j=1;j<=m;j++){
            //     pre[i]=pre[i-1]+a[i][(j+p-1)%m+1];
            // }
            // int sum=0;
            cost[0]=inf;
            for(int j=1;j<=m;j++){
                cost[j]=min(cost[j-1]+a[i][(j+p-1)%m+1],dp[j]+a[i][(j+p-1)%m+1]+k*p);
                // sum+=a[i][(j+p)%m];
            }
            // print(cost);
            for(int j=1;j<=m;j++){
                dp1[j]=min(dp1[j],cost[j]);
            }
            // print(dp1);
        }
        dp=dp1;
    }
    cout<<dp[m]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}