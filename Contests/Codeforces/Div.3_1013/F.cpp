#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
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


const int N1=2e3+10;
const i64 mod=998244353;
i64 a[N1][N1];
i64 dp[N1][N1];
i64 ok[N1][N1];
i64 n,m,d;
void Atomatic_AC_machine(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            // ch='X';
            cin>>ch;
            ok[i][j]=(ch=='X')?1:0;
            if(i==n&&ok[i][j]) dp[i][j]=1;
            else dp[i][j]=0;
        }

    }
    vector<i64> pre(m+1,0),lpre(m+1,0);
    i64 dis=0;//斜着的最大跨度
    for(int i=1;i<=m;i++){
        if(i*i+1<=d*d){
            dis=i;
        }else{
            break;
        }
    }
    for(int i=n;i>=1;i--){
        //处理下层转移过来的
        if(i!=n){
            for(int j=1;j<=m;j++){
                if(ok[i][j]) dp[i][j]=(lpre[min(m,j+dis)]-lpre[max(0ll,j-dis-1)]+mod)%mod;
            }
        }
        //处理当前层
        for(int j=1;j<=m;j++){
            pre[j]=pre[j-1];
            if(ok[i][j]){
                pre[j]=(pre[j]+dp[i][j])%mod;
            }
        }
        for(int j=1;j<=m;j++){
            if(ok[i][j]) dp[i][j]=(pre[min(m,j+d)]-pre[max(0ll,j-d-1)]+mod)%mod;
        }
        for(int j=1;j<=m;j++){
            pre[j]=pre[j-1];
            if(ok[i][j]){
                pre[j]=(pre[j]+dp[i][j])%mod;
            }
        }
        lpre=pre;
    }
    i64 ans=0;
    for(int i=1;i<=m;i++){ 
        ans=(ans+dp[1][i])%mod;
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
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