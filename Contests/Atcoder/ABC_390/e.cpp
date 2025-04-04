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
int dp[N][3];
void Atomatic_AC_machine(){
    int n,c;cin>>n>>c;
    for(int i=1;i<=n;i++){
        int op,v,w;cin>>op>>v>>w;
        op--;
        for(int j=c;j>=w;j--){
             dp[j][op]=max(dp[j][op],dp[j-w][op]+v);
        }
    }
    int ans=0;
    for(int i=0;i<=c;i++){
        for(int j=0;j<=c;j++){
            if(i+j>c) continue;
            int v=c-i-j;
            ans=max(ans,min({dp[i][0],dp[j][1],dp[v][2]}));
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}