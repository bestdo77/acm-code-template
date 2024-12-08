#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=2008;
const int element=3;
int p[64],cnt;//线性基,每一位的线性基
int a[N],b[N];
void insert(int x){//插入一个数x
    for(int i=62;i>=0;i--){
        if(x&(1ll<<i)){
            if(p[i]) x^=p[i];
            else {
                p[i]^=x;
                cnt++;
                break;
            }
        }
    }
}
bool ask(int x){//查询是否有一个数字
    for(int i=62;i>=0;i--){
        if(x&(1ll<<i)){
            if(p[i]) x^=p[i];
        }
    }
    return (x==0);
}
int askmx(){
    int x=0;
    for(int i=63;i>=0;i--){
        if((x^p[i])>x) x^=p[i];
    }
    return x;
}
int askmn(){
    int mn=inf;
    if(cnt==0) return 0;
    else{
        for(int i=0;i<=64;i++){
            if(p[i]) mn=min(mn,p[i]);
        }
        return mn;
    }
}
int quickpow(int x,int y){
    int re=1;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
string s[55];
void Atomatic_AC_machine(){
    int n,m;cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=0;j<m;j++){
            if(s[i][j]=='O') num|=(1ll<<j);
        }
        insert(num);
    }
    cout<<(1ll<<cnt)%mod<<endl;
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