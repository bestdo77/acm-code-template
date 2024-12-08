#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=998244353;
int dp[N];
int quickpow(int x,int y){
    int re=1;
    while(y!=0){
        if(y%2) re=re*x%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int sum1=0,sum2=0;
    for(int i=1;i<=n+1;i++){
        if(i%2==0){
            dp[i]=sum1%mod;
            sum2+=dp[i]%mod;
        }else{
            dp[i]=sum2%mod+1;
            sum1+=dp[i]%mod;
        }
    }
    int ny=quickpow(2,n*(mod-2));
    if(n%2==0) cout<<sum2*ny%mod<<endl;
    else cout<<(sum1*ny)%mod<<endl;
    return 0;
}