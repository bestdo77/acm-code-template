#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64,i64>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
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
    vector<int> a;

    void build(int &x, int l, int r) {
        x = ++idx;
        tr[x].l = l;
        tr[x].r = r;
        if(l==r){
            tr[x].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(x), l, mid);
        build(rs(x), mid+1, r);
    }
    // 构造函数：MAXN_版本数，n_值域范围
    PersistentSegTree(int MAXN_, int n_,vector<int> _a) : MAXN(MAXN_), n(n_), idx(0) {
        tr.resize(MAXN * 32 + 10); // 预分配足够空间
        root.resize(MAXN + 5, 0); // 版本0~MAXN
        a=_a;
        build(root[0], 1, n);
    }


    void change(int new_ver, int old_ver, int pos,int v) {
        modify(root[new_ver], root[old_ver], 1, n, pos,v);
    }

    void modify(int &x, int y, int l, int r, int pos, int v) {
        x = ++idx;
        tr[x] = tr[y];
        if(l == r){
            tr[x].sum=v;
            return;
        } 
        int mid = (l + r) >> 1;
        if(pos <= mid) modify(ls(x), ls(y), l, mid, pos, v);
        else modify(rs(x), rs(y), mid+1, r, pos, v);
    }

    int query(int x_ver, int k) {
        return _query(root[x_ver], 1, n, k);
    }

    int _query(int x, int l, int r, int p) {//区间第k小
        if(l == r) return tr[x].sum;
        int mid = (l + r) >> 1;
        if(p<=mid) return _query(ls(x),l,mid,p);
        else return _query(rs(x),mid+1,r,p);
    }
};

void Atomatic_AC_machine(){
    int n,m; cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    PersistentSegTree seg(m,n,a);
    for(int i=1;i<=m;i++){
        int ver,op;cin>>ver>>op;
        if(op==1){
            int loc,v;
            cin>>loc>>v;
            seg.change(i,ver,loc,v);
        }else{
            int loc;cin>>loc;
            seg.root[i] = seg.root[ver];
            cout<<seg.query(i,loc)<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--) Atomatic_AC_machine();
    return 0;
}