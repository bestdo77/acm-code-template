#include <bits/stdc++.h>
using namespace std;
const int N = 105;
//#define int long long
#pragma GCC optimize(3,"Ofast","inline")

const int mod = 1e9+7;
char a[N][N];
int dp[N][N][21][21][21];//x,y,pretot,mul,num:0,+,-,*

int isop(int x,int y){
	if (a[x][y] =='+'||a[x][y]=='-'||a[x][y]=='*')return 1;
	else return 0;
}
int n,m,k;
int tot(int j){
    int res = 0;
    for (int r = 0;r<k;r++){
        for (int s = 0;s<k;s++){
            for (int t = 0;t<k;t++){
                for (int op = 1;op<=3;op++){
                    res+=dp[j][r][s][t][op];
                }
            }
        }
    }
    return res;
}
int cnt = 0;
int res[N];
signed main (){
	freopen("in.txt","r",stdin);
	freopen("my.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int tt;
	cin >>tt;
	//cout <<tt<<endl;
	while (tt--){
        memset (a,0,sizeof a);
		memset (dp,0,sizeof dp);
		memset (res,0,sizeof res);
		cin >>n>>m>>k;
		
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=m;j++){
				cin >>a[i][j];
			}
		}
		dp[1][1][0][1][(a[1][1]-'0')%k] = 1;
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=m;j++){
                for (int r = 0;r<k;r++){
                    for (int s = 0;s<k;s++){
                        for (int t = 0;t<k;t++){
                            //dp[i-1][j][r][s][t]%=mod;
                           // dp[i][j-1][r][s][t]%=mod;
                            if (i-1>0&&!(isop(i,j)&&isop(i-1,j))){
                                if (a[i][j]=='+'){
                                    dp[i][j][(k*k+r+(s*t))%k][1][0] +=dp[i-1][j][r][s][t];
                                    dp[i][j][(k*k+r+(s*t))%k][1][0]%=mod;
                                }else if (a[i][j] == '-'){
                                    dp[i][j][(k*k+r+(s*t))%k][(k-1)%k][0] +=dp[i-1][j][r][s][t];
                                    dp[i][j][(k*k+r+(s*t))%k][(k-1)%k][0]%=mod;
                                }else if (a[i][j] == '*'){
                                    dp[i][j][r][(k*k+s*t)%k][0]+=dp[i-1][j][r][s][t];
                                    dp[i][j][r][(k*k+s*t)%k][0]%=mod;
                                }else{
                                    dp[i][j][r][s][(t*10+a[i][j]-'0')%k]+=dp[i-1][j][r][s][t];
                                    dp[i][j][r][s][(t*10+a[i][j]-'0')%k]%=mod;
                                }
                            }
                            if (j-1>0&&!(isop(i,j)&&isop(i,j-1))){
                                if (a[i][j]=='+'){
                                    dp[i][j][(k*k+r+(s*t))%k][1][0] +=dp[i][j-1][r][s][t];
                                    dp[i][j][(k*k+r+(s*t))%k][1][0]%=mod;
                                }else if (a[i][j] == '-'){
                                    dp[i][j][(k*k+r+(s*t))%k][(k-1)%k][0] +=dp[i][j-1][r][s][t];
                                    dp[i][j][(k*k+r+(s*t))%k][(k-1)%k][0]%=mod;
                                }else if (a[i][j] == '*'){
                                    dp[i][j][r][(k*k+s*t)%k][0]+=dp[i][j-1][r][s][t];
                                    dp[i][j][r][(k*k+s*t)%k][0]%=mod;
                                }else{
                                    dp[i][j][r][s][(t*10+a[i][j]-'0')%k]+=dp[i][j-1][r][s][t];
                                    dp[i][j][r][s][(t*10+a[i][j]-'0')%k]%=mod;
                                }
                            }
                             if (dp[i][j][r][s][t]<0)while (1);
                        }
                    }
                }
            }
		}
        for (int r = 0;r<k;r++){
            for (int s = 0;s<k;s++){
                for (int t = 0;t<k;t++){
                    res[(k*k+r+s*t)%k]+=dp[n][m][r][s][t];
                    res[(k*k+r+s*t)%k]%=mod;
                }
            }
        }
        cout <<res[0]%mod+1<<endl;
		
	}
}