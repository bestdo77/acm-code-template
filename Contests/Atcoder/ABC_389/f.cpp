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
#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a);
vector<int> generate_data(int n, int range);

void Atomatic_AC_machine(){
    int n;cin>>n;
    Fenwick tr(500000+10);
    for(int i=1;i<=500000;i++){
        tr.add(i,1);
    }
    for(int i=1;i<=n;i++){
        int l,r; cin>>l>>r;
        int ml=tr.select(l);
        int mr=tr.upselect(r);
        mr--;
        tr.add(ml,1);
        tr.add(mr+1,-1);
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int x;cin>>x;
        cout<<tr.sum(x)<<endl;
    }
}   
signed main(){
    
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        //cout << "Case #" << i << ": ";
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
vector<int> generate_data(int n, int range) {
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = 1 + RNG() % range; // 生成 1 到 range 之间的随机数
    }
    return data;
}
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}