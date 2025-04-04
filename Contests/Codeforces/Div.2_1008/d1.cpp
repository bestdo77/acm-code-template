#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
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
pii play[2][N];//add 0,mul 1
int dp[N][2][2];//第i层，全分给0/1时，0/1的结果
void Atomatic_AC_machine(){
    int n;cin>>n;
    int l=1,r=1;
    for(int i=1;i<=n;i++){
        char op;int x;
        cin>>op>>x;
        if(op=='+'){
            play[0][i]={x,0};
        }else{
            play[0][i]={x,1};
        } 
        cin>>op>>x;
        if(op=='+'){
            play[1][i]={x,0};
        }else{
            play[1][i]={x,1};
        } 
    }
    dp[0][0][0]=dp[0][0][1]=dp[0][1][0]=dp[0][1][1]=1;
    for(int i=1;i<=n;i++){
        auto [x0,op0]=play[0][i];
        auto [x1,op1]=play[1][i];
        dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]);
        dp[i][0][1]=max(dp[i-1][1][1],dp[i-1][0][1]);
        int re1=0,re2=0;
        if(op0==0) re1+=x0;
        else re1+=dp[i-1][0][0]*(x0-1);
        if(op1==0) re1+=x1;
        else re1+=dp[i-1][0][1]*(x1-1);

        if(op0==0) re2+=x0;
        else re2+=dp[i-1][1][0]*(x0-1);
        if(op1==0) re2+=x1;
        else re2+=dp[i-1][1][1]*(x1-1);
        db(re1<<" "<<re2)
        cendl
        dp[i][0][0]=max(re1+dp[i-1][0][0],re2+dp[i-1][1][0]);
        dp[i][1][1]=max(re1+dp[i-1][0][1],re2+dp[i-1][1][1]);
    }
    cout<<max(dp[n][0][0]+dp[n][0][1],dp[n][1][0]+dp[n][1][1])<<endl;

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