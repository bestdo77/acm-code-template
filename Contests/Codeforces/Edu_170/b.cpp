#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int C[N1][N1];
int ans[N][2];
int quickpow(int x,int y){
    int re=1;
    while(y){
        if(y&1) re=x*re%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>ans[i][0];
    }
    for(int i=1;i<=t;i++){
        cin>>ans[i][1];
    }
    // for(int i=1;i<=t;i++){}
    for(int i=1;i<=t;i++){
        // cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        if(ans[i][1]==ans[i][0]||ans[i][1]==0){
            cout<<1<<endl;
        }else{
            // cout<<ans[i][1]<<" ";
            cout<<quickpow(2,ans[i][1])<<endl;
        }
    }
    return 0;
}