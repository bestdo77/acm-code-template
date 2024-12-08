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
int f[15][15][2][2];
int tot=0,num[15];
int dp(int x,int sum,int d,bool lim,bool zero){//d表示0-9是要求的，sum表示当前答案
    cout<<x<<" "<<sum<<" "<<d<<endl;
    if(x==0) return sum;
    if(~f[x][sum][lim][zero]) return f[x][sum][lim][zero];//避免被计算过
    int ans=0;
    for(int i=0;i<=(lim?num[x]:9);i++){//是否有上限
        if(zero&&i==0) ans+=dp(x-1,sum,d,0,1);
        //只有当前这一位是0且满足前导零才能转移，否则没有必要使用前导零
        else ans+=dp(x-1,sum+(i==d),d,lim&&(i==num[x]),0);
        //只有考虑上限且这一位是上限的时候，才会转移，否则正常转移
    }
    return f[x][sum][lim][zero]=ans;
}
int cal(int d,int x){
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%10,x/=10;
    return dp(tot,0,d,1,1);
}
void Atomatic_AC_machine(){
    cin>>a>>b;
    for(int i=0;i<=9;i++){
        cout<<cal(i,b)-cal(i,a-1)<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}