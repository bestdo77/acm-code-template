#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a,b,ii,k; 
int f[65][65][2][2];
int num[65],tot;
int kk[65],tt;
int dp(int x,int k,int lim,int zero){
    if(x==0) return 1;
    if(~f[x][k][lim][zero]&&!lim) return f[x][k][lim][zero];
    int ans=0;
    for(int i=0;i<=(lim?num[x]:9);i++){
        if(i==0&&zero){
            if(i<=tt&&num[i]==kk[tt]) ans+=dp(x-1,k+1,lim&&(i==num[x]),1);
            else ans+=dp(x-1,k,lim&&(i==num[x]),1);
        }else {
            if(i<=tt&&num[i]==kk[tt]){
                ans+=dp(x-1,i,lim&&(i==num[x]),0);
            }
        }
    }
    return f[x][k][lim][zero]=ans;
}
int cal(int x){
    if(x==-1) return 0;
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%10,x/=10; 
    return dp(tot,0,0,0);
}
void Atomatic_AC_machine(){
    // int ans=0;
    int n;cin>>n;
    int xr=0;
    for(int i=1;i<=n;i++){
        // if(i%4==0) cout<<endl;
        xr^=i;
        cout<<i<<" "<<bitset<10>(xr)<<endl;
        if(i%4==0) cout<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}·