#include <bits/stdc++.h>
using namespace std;
#define int unsigned int
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int x[N],y[N];
void solve(){
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    cout<<(int)(2147483648+2147483647)<<endl;
    // for(int ans=1;ans<=(int)((int)2147483648);ans++){
    //     int anst=ans;
    //     for(int i=1;i<=q;i++){
    //         anst=x[i]^anst+y[i]^anst;
    //     }
    //     if(anst==ans) cout<<ans<<endl;
    // }
    cout<<4294967295ll%(1ll<<32)<<endl;
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