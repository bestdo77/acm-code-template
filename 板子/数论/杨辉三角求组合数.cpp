const int N=1e4;
int mod=0;
int dp[N][N];
void init(int n){
   dp[1][1]=1;dp[1][2]=1;
   for (int i=2;i<=n;i++){
        for (int j=1;j<=i+1;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}