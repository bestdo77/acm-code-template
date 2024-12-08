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
int f[40][40][40][2][2];
int num[40],tot;
int dp(int x,int c0,int c1,int lim,int zero){
    // cout<<num[x]<<" "<x<<" "<<last<<endl;
    if(x==0) return (c0>=c1);
    if(~f[x][c0][c1][lim][zero]&&!lim) return f[x][c0][c1][lim][zero];
    int ans=0;
    for(int i=0;i<=(lim?num[x]:1);i++){
        if(i==0&&zero) ans+=dp(x-1,0,0,lim&&(num[x]==i),1);
        else ans+=dp(x-1,c0+(i==0),c1+(i==1),lim&&(i==lim),0);
    }
    if(!lim&&!zero) f[x][c0][c1][lim][zero]=ans;
    return ans;
}
int cal(int x){
    // if(x==-1) return 0;
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%2,x/=2; 
    return dp(tot,0,0,1,1);
}
void Atomatic_AC_machine(){
    int ans=0;
    cin>>a>>b;
    // cout<<cal(b)<<endl;
    cout<<cal(b)-cal(a-1)<<endl;
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