#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int suf[N];
vector<int> G[N];
int quickpow(int x,int y){
    int re=1;
    while(y){
        if(y&1) re=re*x%mod,y--;
        x=x*x%mod,y/=2;
    }
    return re%mod;
}
void solve(){
    // cout<<quickpow(2,3)<<endl;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<a[1]<<endl;
        return;
    }
    for(int i=1;i<=n+1;i++){
        suf[i]=0;
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }
    for(int i=n;i>=1;i--){
        suf[i]-=a[i];
        suf[i]%=mod;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=(sum+a[i]*suf[i]%mod)%mod;
    }
    // cout<<sum<<endl;
    cout<<sum*quickpow(n*(n-1)/2%mod,mod-2)%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}