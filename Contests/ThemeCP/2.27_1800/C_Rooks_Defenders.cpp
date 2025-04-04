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
int h1[N],w1[N];
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    Fenwick h(n),w(n);
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            if(!h1[x]) h.add(x,1);
            if(!w1[y]) w.add(y,1);
            h1[x]++;
            w1[y]++;
        }else if(op==2){
            int x,y;cin>>x>>y;
            h1[x]--;
            w1[y]--;
            if(!h1[x]) h.add(x,-1);
            if(!w1[y]) w.add(y,-1);
        }else{
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            if(abs(x1-x2)+1==h.rangeSum(x1,x2)||abs(y1-y2)+1==w.rangeSum(y1,y2)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
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