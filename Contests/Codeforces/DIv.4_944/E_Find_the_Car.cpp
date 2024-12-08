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
double a[N],b[N];
void solve(){
    int n,k,q;cin>>n>>k>>q;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }

    for(int i=1;i<=q;i++){
        int x;cin>>x;
        int p=lower_bound(a+1,a+1+k,x)-a;
        p--;
        // cout<<p<<endl;
        // cout<<a[p]<<" "<<a[p+1]<<endl;
        // cout<<b[p]<<" "<<b[p+1]<<endl;
        cout<<(int)((x-a[p])*(b[p+1]-b[p])/(a[p+1]-a[p])+b[p])<<" ";
    }cout<<endl;
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