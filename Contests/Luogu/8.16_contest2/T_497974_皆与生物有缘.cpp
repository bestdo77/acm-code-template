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
    int ans1=0,ans2=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans1+=x;
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans2+=x;
    }
    cout<<(int)ceil(((double)ans1+double(ans2))/2)<<endl;
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