#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
pii a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;//r,q,x%s==f
        //x=k*s+f;
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int x,d;cin>>x>>d;
        int l=-1,r=1e9;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(mid*a[x].first+a[x].second>=d) r=mid;
            else l=mid;
        }
        // cout<<r<<" "<<a[x].second<<endl;
        cout<<r*a[x].first+a[x].second<<endl;
    }
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