#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n,l,r;cin>>n>>l>>r;
    l--,r--;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i<=r) a.emplace_back(x);
        if(i>=l) b.emplace_back(x); 
    }
    print(a);
    print(b);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans1=0;
    int ans2=0;
    ans1=accumulate(a.begin(),a.begin()+(r-l+1),0ll);
    ans2=accumulate(b.begin(),b.begin()+(r-l+1),0ll);
    cout<<min(ans1,ans2)<<endl;
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