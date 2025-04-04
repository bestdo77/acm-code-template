#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 10;
const int N1 = 5e3 + 10;
const int mod = 998244353;

#define db(x) cerr << x << " ";
#define cendl cerr << endl;
void print(vector<int> a) { for (auto it : a) db(it); cendl; }

int a[N];
int n, ans;
int dp[N][2];
void Atomatic_AC_machine() {
    cin >> n;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i][1]=0;
    }
    dp[0][1]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=(dp[i][0]+dp[i-1][1])%mod;
        if(a[i]==a[i-1]){//i-1为真
            dp[i][1]=(dp[i][1]+dp[i-1][1])%mod; 
        }
        if(i>=2&&a[i]==a[i-2]+1){//i-1为假
            dp[i][1]=(dp[i][1]+dp[i-2][1])%mod;
        }   
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][1]<<" ";
    // }
    // cout<<endl;
    cout<<(dp[n][1]+dp[n][0])%mod<<endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        Atomatic_AC_machine();
    }
    return 0;
}