#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int dp[410][410][410];
int a[maxn];
int mod = 167772161;

int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            
            for(int p=0;p<=k;p++){
                (dp[i][j][p] += dp[i-1][j][p])%=mod;
                int g = p + a[i];
                if(g>k) continue;
                (dp[i][j+1][g] += dp[i-1][j][p])%=mod;
            }
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 1;j<=k;j++){
            (dp[n][i][j] += dp[n][i][j-1])%=mod;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<n;j++){
            cout<<((dp[n][k] - dp[n][k-a[i]+1])%mod + mod)%mod<<" ";
        }
        cout<<endl;
    }
}