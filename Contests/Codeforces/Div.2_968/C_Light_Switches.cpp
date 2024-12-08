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
const int xx=1e9;
int a[N];
// int ans[N];
int n,k;
bool check(int x,int i){
    return a[i]+(2*x)*k<=a[n]+k-1;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int minn=inf,maxx=0;
    for(int i=1;i<=n-1;i++){
        int l=-1,r=1e9+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(check(mid,i)) l=mid;
            else r=mid;
        }
        // cout<<a[i]<<" "<<l<<" "<<r<<endl;
        minn=min(minn,a[i]+2*l*k);
        maxx=max(maxx,a[i]+2*l*k);
    }
    // cout<<maxx<<" "<<minn<<endl;
    int ans=inf;
    maxx=max(maxx,a[n]);
    if(minn+k-1>=maxx) ans=maxx;

    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;

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