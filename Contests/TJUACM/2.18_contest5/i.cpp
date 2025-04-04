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
int dp[20][10];
void Atomatic_AC_machine(){
    for(int i=1;i<=9;i++){
        dp[1][i]=dp[1][i-1]+i;
    }
    int sum=0;
    int nine=0;
    for(int i=2;i<=18;i++){
        for(int j=0;j<=9;j++){
            if(j==0) dp[i][j]=0;
            else if(j==1){
                sum+=sum+(i==2?0:81);
                dp[i][j]=sum+1;
            }else dp[i][j]=(dp[i][1]+(j-1)*10+dp[i][j-1])%mod;;
        }
    }
    string s;cin>>s;
    s=" "+s;
    int ans=0;
    for(int i=1;i<=18;i++){
        for(int j=0;j<=9;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int cnt=0;
    for(int i=s.size()-1;i>=1;i--){
        ans=((ans+dp[s.size()-i][s[i]-'0'])%mod+cnt*(s[i]-'0'))%mod;
        cnt*=10;
        cnt+=s[i]-'0';
        cnt%=mod;
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