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
    vector<i64> fac(N+1,0);
    for(int i=2;i<=N;i++){
        if(fac[i]==0){
            for(int j=i;j<=N;j+=i){
                fac[j]++;
            }
        }
    }
    vector<i64> vec;
    for(i64 i=2;i<=N;i++){
        if(fac[i]==2) vec.push_back(i*i);
    }
    // db(vec.size())
    // cendl
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        i64 x;cin>>x;
        cout<<*prev(upper_bound(all(vec),x))<<endl;
    }
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