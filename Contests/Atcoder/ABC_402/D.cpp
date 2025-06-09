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
    i64 n,m;cin>>n>>m;
    i64 ans1=m*(m-1)/2;
    vector<i64> cnt(n,0);
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        cnt[(x+y)%n]++;
    }
    for(int i=0;i<n;i++){
        ans1-=cnt[i]*(cnt[i]-1)/2;
    }
    cout<<ans1<<endl;
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