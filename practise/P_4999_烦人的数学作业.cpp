#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a,b; 
int f[25][20][2][2];
int num[20],tot;
int dp(int x,int sum,int d,int lim,int zero){
    // cout<<sum<<endl;
    if(x==0) return 1;
    if(~f[x][sum][lim][zero]) return f[x][sum][lim][zero];
    int ans=0;
    for(int i=0;i<=(lim?num[x]:9);i++){
        if(abs(i-d)<2) continue;
        if(i==0&&zero) ans+=dp(x-1,sum,d,0,1);
        else ans+=dp(x-1,sum+(i==d),d,lim&&(i==num[x]),0);
    }
    return f[x][sum][lim][zero]=ans;
}
int cal(int x,int d){
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%10,x/=10; 
    return dp(tot,0,d,1,1);
}
void Atomatic_AC_machine(){
    int ans=0;
    cin>>a>>b;
    for(int i=0;i<=9;i++){
        // cout<<cal(b,i)-cal(a-1,i)<<" ";
        ans=(ans+i*(cal(b,i)-cal(a-1,i))%mod+mod)%mod;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}