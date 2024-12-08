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
    // int n;cin>>n;
    int l,r;cin>>l>>r;
    if(l%2){
        cout<<(r-l+1)/4+(int)((r-l+1)%4==3)<<endl;
    }else{
        cout<<(r-l)/4+(int)((r-l)%4==3)<<endl;
    }
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