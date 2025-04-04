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
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
#include <bits/stdc++.h>
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
int p[N];
int ans[N];
bool cmp(int x,int y){
    return ans[x]<ans[y];
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    Fenwick f(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        f.add(i,1);
    }
    for(int i=n;i>=1;i--){
        ans[i]=f.select(p[i]);
        f.add(ans[i],-1);
    }
    vector<int> ans1(n+1,0);
    iota(ans1.begin(),ans1.end(),1);
    sort(ans1.begin(),ans1.end(),cmp);
    for(int i=1;i<=n;i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
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