#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

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
int n,m,k;
int E(int sum,int mul,int cur){
    return (sum*k+mul)*k+cur;
}
int ce[128][21*21*21];//state -op> ce[op][state]
int dp[101][101][21*21*21];//dp[i][j][num][mul][cur]
char mp[200][200];
void Atomatic_AC_machine(){
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int sum=0;sum<k;sum++){
        for(int mul=0;mul<k;mul++){
            for(int cur=0;cur<k;cur++){
                int now=E(sum,mul,cur);
                for(char ch='0';ch<='9';ch++){
                    ce[ch][now]=E(sum,mul,(cur*10+ch-'0')%k);
                }
                ce['+'][now]=E((sum+mul*cur)%k,1,0); 
                ce['-'][now]=E((sum+mul*cur)%k,k-1,0);
                ce['*'][now]=E(sum,(mul*cur)%k,0);
            }
        }
    }
    mp[n][m+1]='+';
    dp[1][1][E(0,1,(mp[1][1]-'0')%k)]=1;
    for(int i=1;i<=n;i++){
        for(int j=1+(i==1);j<=m+(i==n);j++){
            char ch=mp[i][j];
            for(int st=0;st<k*k*k;st++){
                if(isdigit(ch)||isdigit(mp[i-1][j]))
                dp[i][j][ce[ch][st]]=(dp[i-1][j][st]+dp[i][j][ce[ch][st]])%mod;
                if(isdigit(ch)||isdigit(mp[i][j-1])) 
                dp[i][j][ce[ch][st]]=(dp[i][j-1][st]+dp[i][j][ce[ch][st]])%mod;
            }
        }
    }
    cout<<dp[n][m+1][E(0,1,0)]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}