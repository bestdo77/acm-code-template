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
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(10,0),ndp(10,0),emp(10,0);
    dp[a[1]]=1;
    for(int i=2;i<=n;i++){
        ndp=emp;
        for(int j=0;j<=9;j++){
            if(dp[j]){
                ndp[(j*a[i])%10]=(ndp[(j*a[i])%10]+dp[j])%mod;
                ndp[(j+a[i])%10]=(ndp[(j+a[i])%10]+dp[j])%mod;
            }      
        }
        dp=ndp;
        // print(dp);
    }
    for(int i=0;i<=9;i++){
        cout<<dp[i]<<endl;
    }
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