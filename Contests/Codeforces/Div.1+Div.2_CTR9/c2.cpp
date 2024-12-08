#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int vis[N];
void Atomatic_AC_machine(){
    int x,m;cin>>x>>m;
    int ans=0;
    for(int i=1;i<=min(x,m);i++){
        if((x^i)%i==0){
            ans++;
        }
    }
    if(m>x){
        ans+=m/x-1;
        int sm=(m/x)*x;
        sm=max(2*x,sm-100*x);
        for(int i=0;i<=200;i++){
            int p=sm^x;//p must leq m
            if(sm<=m&&p>m) ans--;
            else if(sm>m&&p<=m) ans++;
            sm+=x;
        }
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