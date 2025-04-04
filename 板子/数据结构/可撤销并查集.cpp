#include <bits/stdc++.h>
using namespace std;
struct PersistentArray {
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
    PersistentArray(){};
    // 构造函数：MAXN_版本数，n_值域范围
    PersistentArray(int MAXN_, int n_,vector<int> _a) : MAXN(MAXN_), n(n_), idx(0) {
        tr.resize(MAXN * 32); // 预分配足够空间
        root.resize(MAXN+1, 0); // 版本0~MAXN
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

    int _query(int x, int l, int r, int p) {
        if(l == r) return tr[x].sum;
        int mid = (l + r) >> 1;
        if(p<=mid) return _query(ls(x),l,mid,p);
        else return _query(rs(x),mid+1,r,p);
    }
};
struct undoDsu {
    PersistentArray f, rk;
    int nv = 0; // 当前版本号
    int mx= 0;
    undoDsu(int m, int n) { // m:最大操作次数，n:元素数量
        vector<int> _f(n + 1), _rk(n + 1, 1);
        iota(_f.begin(), _f.end(), 0);
        f = PersistentArray(m, n, _f);
        rk = PersistentArray(m, n, _rk);
    }

    int find(int ver, int x) {
        int fx = f.query(ver, x);
        return fx == x ? x : find(ver, fx);
    }

    void merge(int ver,int x, int y) {
        int fx = find(ver, x);
        int fy = find(ver, y);
        if (fx != fy) {
            int rkx = rk.query(ver, fx);
            int rky = rk.query(ver, fy);
            if (rkx < rky) swap(fx, fy);
            
            nv++;
            f.change(nv, ver, fy, fx); // 合并fy到fx
            rk.change(nv, ver, fx, rkx + rky);
        }else{
            nv++;
            f.change(nv, ver, fy, fy); // 合并fy到fx
            int rkx = rk.query(ver, fx);
            rk.change(nv, ver, fx, rkx);
        }
    }

    void undo(int ver) { // 回退到指定版本,跟创建新版本一样
        merge(ver,1,1);
    }

    bool same(int x, int y) {
        merge(nv,1,1);
        return find(nv, x) == find(nv, y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    undoDsu dsu(m, n);
    for (int i = 1; i <= m; ++i) {
        int op, a, b, k;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            dsu.merge(dsu.nv, a, b);
        } else if (op == 2) {
            cin >> k;
            dsu.undo(k);
        } else {
            cin >> a >> b;
            cout << (dsu.same(a, b) ? 1 : 0) << endl;
        }
    }
    return 0;
}
