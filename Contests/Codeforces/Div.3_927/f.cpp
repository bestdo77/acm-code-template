#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int dp[N];
int line[N],mx[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        line[l]++,line[r+1]--;
        mx[l]=max(mx[l],r);
    }
    for(int i=1;i<=n;i++){
        mx[i]=max(mx[i],mx[i-1]);
        line[i]+=line[i-1];
    }
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        dp[mx[i]]=max(dp[mx[i]],dp[i-1]+line[i]);
    }
    // pa(mx,n);    
    // pa(dp,n);
    cout<<dp[n]<<endl;
    for(int i=1;i<=n+1;i++){
        dp[i]=mx[i]=line[i]=0;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}