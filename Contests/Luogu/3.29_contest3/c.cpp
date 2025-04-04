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
    int n,m,k;cin>>n>>m>>k;
    vector<i64> a(n+1,0),b(m+1,0),c(k+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    i64 mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int t=1;t<=k;t++){
                mx=max(a[i]*b[j]%c[t],mx);
            }
        }
    }
    cout<<mx<<endl;
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