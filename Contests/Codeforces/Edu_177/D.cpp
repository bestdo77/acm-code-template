#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif


const int N1=5e3+10;
const i64 mod=998244353;
const int N = 5e5 + 10; // 调整预处理范围
i64 f[N], inv_fact[N];

i64 quickpow(i64 x, i64 y) {
    i64 res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void init() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) 
        f[i] = f[i-1] * i % mod;
    
    inv_fact[N-1] = quickpow(f[N-1], mod-2);
    for (int i = N-2; i >= 0; --i)
        inv_fact[i] = inv_fact[i+1] * (i+1) % mod;
}
void Atomatic_AC_machine(){
    vector<i64> ch(26,0);
    for(int i=0;i<26;i++){
        cin>>ch[i];
    }
    i64 mul=1;
    i64 sum=0;
    for(int i=0;i<26;i++){
        if(ch[i]) mul=mul*f[ch[i]]%mod;
        sum+=ch[i];
    }
    i64 O=sum/2,E=sum/2+sum%2;
    vector<i64> dp(E+1);//奇数偶数随便
    dp[0]=1;
    for(int i=0;i<26;i++){
        if(!ch[i]) continue;
        for(int j=E;j>=ch[i];j--){//从大到小
            if(dp[j-ch[i]]) dp[j]=(dp[j]+dp[j-ch[i]])%mod;//选到奇数
        }
    }
    if(!dp[E]){
        cout<<0<<endl;
        return;
    }
    i64 ans = f[E] * f[O] % mod;
    ans = ans * quickpow(mul, mod-2) % mod;
    ans = ans * dp[E] % mod; // 乘以分配方案数
    
    cout << ans << endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    db((1ll<<14))
    cendl
    int t=1,i=0;
    cin>>t;
    init();
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}