#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int element=3;
int a[N];
vector<int> G[N];
const int maxn = 2e5+10;
const int mod = 1e9+7;
int fac[maxn], ifac[maxn];
int ksm(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            res = res * a % mod;
    }
    return res;
}
int C(int n, int m) {  // m是小的数字，n是大的
    if(m==0) return 1;
    if (n < m || m < 0)
        return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int invC(int n, int m) {
    return ifac[n] * fac[m] % mod * fac[n - m] % mod;
}
void init() {
    fac[0] = 1;  // 阶乘预处理
    for (int i = 1; i <= maxn - 5; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[maxn - 5] = ksm(fac[maxn - 5], mod - 2);
    for (int i = maxn - 5; i; i--)  // 换着写可能导致0的逆元变成0
        ifac[i - 1] = ifac[i] * i % mod;
}
void solve(){
    int n,k;cin>>n>>k;
    int cnt1=0,cnt0=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==0) cnt0++;
        else cnt1++;
    }
    int ans=0;
    for(int i=k/2+1;i<=k;i++){
        if(i>cnt1||k-i>cnt0) continue;
        ans+=C(cnt1,i)*C(cnt0,k-i)%mod;
        ans%=mod;
    }
    cout<<ans%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}