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
int f[25][25][2][2];
int num[20],tot;
int dp(int x,int last,int lim,int zero){
    // cout<<num[x]<<" "<x<<" "<<last<<endl;
    if(x==0) return 1;
    if(~f[x][last][lim][zero]) return f[x][last][lim][zero];
    int ans=0;
    for(int i=0;i<=(lim?num[x]:9);i++){
        if(abs(last-i)<2) continue;
        if(i==0&&zero){
            ans+=dp(x-1,-10,lim&&(i==num[x]),1);
        }else ans+=dp(x-1,i,lim&&(i==num[x]),0);
    }
    f[x][last][lim][zero]=ans;
    return ans;
}
int cal(int x){
    // if(x==-1) return 0;
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%2,x/=10; 
    return dp(tot,-10,1,1);
}
void Atomatic_AC_machine(){
    int ans=0;
    cin>>a>>b;
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