#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
double dp[510][510][510];
int a[4];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[x]++;
    }
    for(int k=0;k<=n;k++){
        for(int j=0;j<=n;j++){
            for(int i=0;i<=n;i++){
                double sum=i+j+k;
                if(sum==0) continue;
                if(i) dp[i][j][k]+=i*dp[i-1][j][k];
                if(j) dp[i][j][k]+=j*dp[i+1][j-1][k];
                if(k) dp[i][j][k]+=k*dp[i][j+1][k-1];
                dp[i][j][k]+=n;
                dp[i][j][k]/=sum;
            }
        }
    }
    printf("%.12lf\n",dp[a[1]][a[2]][a[3]]);
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}