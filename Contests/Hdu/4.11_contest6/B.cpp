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
    int n;cin>>n;
    vector<i64> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int l=0;
    i64 ans=0;
    i64 cur=0;
    for(int i=1;i<=n;i++){
        if(a[i]+b[i]==a[l]+b[l]){
            cur+=a[i];
        }else{
            ans=max(ans,cur*(i-l));
            l=i;
            cur=a[i];
        }
    }
    ans=max(ans,cur*(n-l+1));
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