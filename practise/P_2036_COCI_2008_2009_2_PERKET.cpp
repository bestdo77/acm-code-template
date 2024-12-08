#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
pii a[N];
int n;
int sour=1,bit;
int minabs=inf;
void dfs(int x,int cnt){
    if(x>n){
        if(cnt==0) return;
        minabs=min(abs(sour-bit),minabs);
        return;
    }
    sour*=a[x].first;
    bit+=a[x].second;
    cnt++;
    dfs(x+1,cnt);
    sour/=a[x].first;
    bit-=a[x].second;
    cnt--;
    dfs(x+1,cnt);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    dfs(1,0);
    cout<<minabs<<endl;
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