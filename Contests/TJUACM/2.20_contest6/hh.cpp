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
const int mod=998244353;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
void pa(int *p,int n){for(int i=1;i<=n;i++){db(*(p+i))} cendl}
int pow2[N];
int ansd[N];
int cnt[N];
int prepow2[N];
void Atomatic_AC_machine(){
    int n,d;cin>>n>>d;
    pow2[0]=1;
    for(int i=1;i<=n;i++){
        pow2[i]=(2*pow2[i-1])%mod;
    }
    int ans=0;
    for(int i=0;i<=d;i++){
        int j=d-i;
        if(max(i,j)>=n) continue;
        int rt=(pow2[max(0ll,n-max(i,j))]-1+mod)%mod;
        int lsz=(pow2[max(0ll,i-1)])%mod;
        int rsz=(pow2[max(0ll,j-1)])%mod;
        // db(lsz<<" "<<rsz<<" "<<rt)
        // cendl
        ans=(ans+((rt*lsz)%mod*rsz)%mod)%mod;
    }
    ans=(ans*2%mod);
    cout<<ans<<endl;
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}