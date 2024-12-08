#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    int l=1,r=2;
    int ans=0;
    for(int i=1;i<=q;i++){
        char hand;int des;
        cin>>hand>>des;
        if(hand=='L'){
            ans+=min(abs(l-des),n-abs(l-des));
            l=des;            
        }else{
            ans+=min(abs(r-des),n-abs(r-des));
            r=des;
        }
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
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