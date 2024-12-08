#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
set<int> sets;
int dis(int x,int y){
    return abs(x-y);
}
void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=q;i++){
        int b,k;cin>>b>>k;
        int l=-1,r=200000000+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(((upper_bound(a+1,a+n+1,b+mid))-(lower_bound(a+1,a+n+1,b-mid)))>=k) r=mid;
            else l=mid;
        }
        cout<<r<<endl;
    }
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