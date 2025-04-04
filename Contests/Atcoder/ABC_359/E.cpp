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
string s;
bool vis[N];
bool check(int x,int k){
    int i=0,j=k-1;
    while(i<=j){
        if(!!(x&(1<<i))!=!!(x&(1<<j))){
            return 1;
        }
        i++,j--;
    }   
    return 0;
}
int dp[N1][N1];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    string s;cin>>s;   
    s=" "+s;
    for(int i=0;i<(1<<k);i++){
        vis[i]=check(i,k);
    }
    for(int i=0;i<(1<<k);i++){
        bool flag=vis[i];
        for(int j=0;j<k;j++){
            if(!(i&(1<<j))){
                if(s[j+1]=='B'){
                    flag=0;
                    break;
                }
            }else{
                if(s[j+1]=='A'){
                    flag=0;
                    break;
                }
            }
        }
        dp[k][i]=flag;
    }
    // for(int i=0;i<(1<<k);i++){
    //     db(vis[i])
    // }
    // cendl
    int ff=(1<<k)-1;
    // db(check(0,k))
    // db(bitset<64>(ff))
    for(int i=k+1;i<=n;i++){
        for(int j=0;j<(1<<k);j++){
            if(dp[i-1][j]){
                if(s[i]=='A'||s[i]=='?'){
                    if(vis[(j>>1)]) dp[i][(j>>1)&ff]=(dp[i][(j>>1)&ff]+dp[i-1][j])%mod;
                }
                if(s[i]=='B'||s[i]=='?'){
                    if(vis[((j>>1)|(1<<(k-1)))]) dp[i][((j>>1)|(1<<(k-1)))]=(dp[i][((j>>1)|(1<<(k-1)))]+dp[i-1][j])%mod;
                }
            }    
        }
    }
    int ans=0;
    for(int i=0;i<(1<<k);i++){
        ans=(ans+dp[n][i])%mod;
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