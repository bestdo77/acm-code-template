#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int dp[N1][N1][2];
int a[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j][0]=dp[i][j][1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j][0]=dp[i-1][j][0];//不选的
            
            if(i>=2) dp[i][j][1]=dp[i-2][j][0]+a[i]+a[i-1];//选的
            else dp[1][j][1]=dp[2][j][1]=a[1]+a[2];

            if(dp[i-1][j][1]) dp[i][j][0]=max(dp[i-1][j][1]+a[i],dp[i][j][0]);//可能因为前面选了吃到x            
        }
    }
    cout<<max(dp[n][k][1],dp[n][k][0])<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}