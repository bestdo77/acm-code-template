#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
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

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
struct Fenwick {
    int n;
    std::vector<int> a;
    
    Fenwick(int n_ = 0) { // capacity is n
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, 0); // 1-index, so we need n+1 elements
    }
    
    void add(int x, const int &v) { // x is 1-index
        for (int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    
    int sum(int x) { // query sum of the first x numbers (1-index)
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    
    int rangeSum(int l, int r) { // 1-index, inclusive
        return sum(r) - sum(l - 1);
    }
    
    int select(const int &k) { // find the first x that sum[x] >= k (1-index)
        int x = 0;
        int cur = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] < k) {
                x += i;
                cur += a[x];
            }
        }
        // x is the largest index where sum[x] < k, so x + 1 is the first index where sum[x] >= k
        return x + 1;
    }
    
    int upselect(const int &k) { // find the first x that sum[x] > k (1-index)
        int x = 0;
        int cur = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur += a[x];
            }
        }
        // x is the largest index where sum[x] <= k, so x + 1 is the first index where sum[x] > k
        return x + 1;
    }
};
int sm[N],sm1[N],bg[N],bg1[N];
int a[N];
int cnt[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    Fenwick f(m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]++;
        cnt[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        sm[a[i]]+=f.sum(a[i]-1);
        bg1[a[i]]+=f.rangeSum(a[i]+1,m);
        f.add(a[i],1);
    }
    for(int i=1;i<=m;i++){
        f.a[i]=0;
    }
    for(int i=1;i<=n;i++){
        bg[a[i]]+=f.rangeSum(a[i]+1,m);
        sm1[a[i]]+=f.sum(a[i]-1);
        f.add(a[i],1);
    }
    int ans=accumulate(sm+1,sm+1+m,0ll);
    cout<<ans<<endl;
    int pre=0;
    for(int i=m;i>=2;i--){
        ans=ans+sm1[i]+bg[i]-sm[i]-bg1[i];
        cout<<ans<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}