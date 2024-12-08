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
vector<int> G[N];
void solve(){
    int n;cin>>n;
    int lastL=0,lastR=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int p;char op;
        cin>>p>>op;
        if(op=='L'){
            if(!lastL) lastL=p;
            else ans+=abs(p-lastL),lastL=p; 
        }else{
            if(!lastR) lastR=p;
            else ans+=abs(p-lastR),lastR=p; 
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}