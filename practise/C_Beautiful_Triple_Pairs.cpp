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
map<tuple<int,int,int>,int> maps;
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n-2;i++){
        ans+=maps[{a[i],a[i+1],0}]++;
        ans+=maps[{a[i],0,a[i+2]}]++;
        ans+=maps[{0,a[i+1],a[i+2]}]++;
        ans-=3*(maps[{a[i],a[i+1],a[i+2]}]++);
    }
    cout<<ans<<endl;
    maps.clear();
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