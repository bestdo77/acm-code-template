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
    i64 n1;cin>>n1;
    __int128 n=n1;
    i64 cnt=0;
    for(int i=1;i<=63;i++){
        if((1ll<<i)>n) break;
        __int128 l=0,r=sqrt(n/(__int128(1)<<i))+10;
        while(l+1<r){
            __int128 mid=(l+r)>>1;
            if(mid*mid*(1ll<<i)<=n) l=mid;
            else r=mid;
        }
        cnt+=l;
        cnt-=l/2;
    }
    cout<<cnt<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}