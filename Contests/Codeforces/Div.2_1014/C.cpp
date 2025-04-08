#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    i64 n;cin>>n;
    vector<i64> a(n);
    i64 O=0,E=0;
    i64 mxO=0,mxE=0;
    i64 cntO=0,cntE=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2) cntO++,mxO=max(mxO,a[i]),O+=a[i];
        else cntE++,mxE=max(mxE,a[i]),E+=a[i];
    }
    i64 ans=0;
    if(cntO){
        ans=max(ans,mxO+E+min(O-mxO-cntO+1ll,E));
    }
    if(cntE){
        ans=max(ans,mxE+O+min(O,E-mxE-cntE+1ll));
    }   
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}