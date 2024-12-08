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
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for(auto it:s){
        a[it-'A']++;
    }
    int ans=0;
    for(int i=0;i<4;i++){
        ans+=min(n,a[i]);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    for(int i=0;i<4;i++) a[i]=0;
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