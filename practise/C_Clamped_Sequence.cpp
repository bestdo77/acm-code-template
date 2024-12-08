#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e5+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int tmp[N];
int n,d;
vector<int> G[N];
int cal(int l,int r){
    for(int i=1;i<=n;i++){
        if(a[i]<=l) tmp[i]=l;
        else if(a[i]>=r) tmp[i]=r;
        else tmp[i]=a[i];
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        ans+=abs(tmp[i+1]-tmp[i]);
    }
    return ans;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(cal(a[i],a[i]+d),ans);
        ans=max(cal(a[i]-d,a[i]),ans);
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cout<<1,2<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}