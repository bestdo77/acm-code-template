#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64,i64>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

struct PersistentSegTree {
    #define ls(x) tr[x].l
    #define rs(x) tr[x].r
        
    struct Segment{ int l,r,sum; };
    vector<Segment> tr;
    vector<int> root;
    int idx;
    int n; // 值域范围
    int MAXN; // 最大版本数

    // 构造函数：MAXN_版本数，n_值域范围
    PersistentSegTree(int MAXN_, int n_) : MAXN(MAXN_), n(n_), idx(0) {
        tr.resize(MAXN * 32 + 10); // 预分配足够空间
        root.resize(MAXN + 5, 0); // 版本0~MAXN
        build(root[0], 1, n);
    }

    void build(int &x, int l, int r) {
        x = ++idx;
        tr[x].l = l;
        tr[x].r = r;
        tr[x].sum = 0;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(ls(x), l, mid);
        build(rs(x), mid+1, r);
    }

    void insert(int new_ver, int old_ver, int pos) {
        modify(root[new_ver], root[old_ver], 1, n, pos);
    }

    void modify(int &x, int y, int l, int r, int pos) {
        x = ++idx;
        tr[x] = tr[y];
        tr[x].sum++;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid) modify(ls(x), ls(y), l, mid, pos);
        else modify(rs(x), rs(y), mid+1, r, pos);
    }

    int query(int x_ver, int y_ver, int k) {
        return _query(root[x_ver], root[y_ver], 1, n, k);
    }

    int _query(int x, int y, int l, int r, int k) {//区间第k小
        if(l == r) return l;
        int mid = (l + r) >> 1;
        int cnt = tr[ls(y)].sum - tr[ls(x)].sum;
        return cnt >= k ? _query(ls(x), ls(y), l, mid, k)
                        : _query(rs(x), rs(y), mid+1, r, k - cnt);
    }
};

int a[N],b[N],id[N];
void Atomatic_AC_machine(){
    int n,m,bn; 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    bn=unique(b+1,b+1+n)-b;
    bn--;
    PersistentSegTree seg(n+2,bn);
    for(int i=1;i<=n;i++){
        id[i]=lower_bound(b+1,b+1+bn,a[i])-b;//a[i]的id
    }
    for(int i=1;i<=n;i++){
        seg.insert(i,i-1,id[i]);
    }
    for(int i=1;i<=m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<b[seg.query(l-1,r,k)]<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}