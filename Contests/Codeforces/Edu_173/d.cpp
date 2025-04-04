#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
void Atomatic_AC_machine(){
    int l,r,d;cin>>l>>r>>d;
    int l1=l/d;
    if(l1*d<l) l1++;
    int r1=r/d;
    db(l1<<" "<<r1)
    cendl
    for(int dd=r1-l1;dd>=0;dd--){
        for(int i=l1;i+dd<=r1;i++){
            if(__gcd(i,i+dd)==1){
                cout<<i*d<<" "<<(i+dd)*d<<endl;
                return;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}