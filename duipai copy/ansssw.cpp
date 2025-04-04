


#include<iostream>
#include<cstring>
#include<cstdio>

const int N = 105;
const int P = 1e9 + 7;
int n,m,k;
int dp[N][N][22][22][22];
char s[N][N];

int isNum(char c)
{
    return c <= '9' && c >= '0';
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("ansssw.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;++i)
            scanf("%s",s[i] + 1);
        //printf("c : %c\n",s[1][1]);
        dp[1][1][0][1][(s[1][1] - '0') % k] = 1;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                for(int A = 0;A < k;++A)
                {
                    for(int B = 0;B < k;++B)
                    {
                        for(int C = 0;C < k;++C)
                        {
                            if(C && !isNum(s[i][j]))continue;
                            if(j < m)
                            {
                                if(isNum(s[i][j]))
                                {
                                    if(isNum(s[i][j+1]))
                                    {
                                        int D = (C * 10 + s[i][j + 1] - '0') % k;
                                        dp[i][j+1][A][B][D] = (dp[i][j+1][A][B][D] + dp[i][j][A][B][C]) % P; 
                                    }
                                    else
                                    {
                                        if(s[i][j+1] == '*')
                                        {
                                            int D = (C * B) % k;
                                            dp[i][j+1][A][D][0] = (dp[i][j+1][A][D][0] + dp[i][j][A][B][C]) % P;
                                        }
                                        else
                                        {
                                            int D = (A + C * B) % k;
                                            int E = (s[i][j+1] == '+' ? 1 : k-1);
                                            dp[i][j+1][D][E][0] = (dp[i][j+1][D][E][0] + dp[i][j][A][B][C]) % P;
                                        }
                                    }
                                }
                                else
                                {
                                    if(isNum(s[i][j+1]))
                                    {
                                        int D = (s[i][j+1]-'0') % k;
                                        dp[i][j+1][A][B][D] = (dp[i][j+1][A][B][D] + dp[i][j][A][B][C]) % P;  
                                    }
                                }
                            }
                            if(i < n)
                            {
                                if(isNum(s[i][j]))
                                {
                                    if(isNum(s[i+1][j]))
                                    {
                                        int D = (C * 10 + s[i+1][j] - '0') % k;
                                        dp[i+1][j][A][B][D] = (dp[i+1][j][A][B][D] + dp[i][j][A][B][C]) % P; 
                                    }
                                    else
                                    {
                                        if(s[i+1][j] == '*')
                                        {
                                            int D = (C * B) % k;
                                            dp[i+1][j][A][D][0] = (dp[i+1][j][A][D][0] + dp[i][j][A][B][C]) % P;
                                        }
                                        else
                                        {
                                            int D = (A + C * B) % k;
                                            int E = (s[i+1][j] == '+' ? 1 : k-1);
                                            dp[i+1][j][D][E][0] = (dp[i+1][j][D][E][0] + dp[i][j][A][B][C]) % P;
                                        }
                                    }
                                }
                                else
                                {
                                    if(isNum(s[i+1][j]))
                                    {
                                        int D = (s[i+1][j] - '0') % k;
                                        dp[i+1][j][A][B][D] = (dp[i+1][j][A][B][D] + dp[i][j][A][B][C]) % P;  
                                    }
                                }
                            }
                        }
                    }       
                }
            }
        }
        //printf("%d\n",dp[3][3][0][2][0]);
        int ans = 0;
        for(int A = 0;A < k;++A)
            for(int B = 0;B < k;++B)
                for(int C = 0;C < k;++C)
                {
                    //if(dp[n][m][A][B][C])
                     //   printf("%d : %d\n",(A + B * C) % k,dp[n][m][A][B][C]);
                    if((A + B * C) % k == 0)
                        ans = (ans + dp[n][m][A][B][C]) % P;
                }
        printf("%d\n",ans);
    }
}

