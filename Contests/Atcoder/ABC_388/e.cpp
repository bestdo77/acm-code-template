#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
multiset<int> st;
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2){
        if(a[2]>=2*a[1]){
            cout<<1<<endl;
            return;
        }
    }
    int ll=n/2,rr=n/2+1;
    int l=1,r=n;
    int ans=0;
    while(a[rr]<2*a[ll]&&r>=ll&&ll<=r&&rr<=n&&ll>=1){
        if(a[rr]>=2*a[l]) l++,ans++;
        if(a[r]>=2*a[ll]) r--,ans++;
        ll--,rr++;
    }
    ans+=max(0ll,min({ll-l+1,r-rr+1}));
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