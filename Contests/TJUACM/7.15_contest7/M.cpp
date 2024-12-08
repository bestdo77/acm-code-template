#include <algorithm>
#include <cstdio>
#include <iostream>

#define maxn 4000500
#define INF (1 << 30)
int abb[4000050][2];
int anss[4000050][2];
int n;

struct treap {  // 直接维护成数据结构，可以直接用
  int l[maxn], r[maxn], val[maxn], rnd[maxn], size_[maxn], w[maxn];
  int sz, ans, rt;

  void pushup(int x) { size_[x] = size_[l[x]] + size_[r[x]] + w[x]; }

  void lrotate(int &k) {
    int t = r[k];
    r[k] = l[t];
    l[t] = k;
    size_[t] = size_[k];
    pushup(k);
    k = t;
  }

  void rrotate(int &k) {
    int t = l[k];
    l[k] = r[t];
    r[t] = k;
    size_[t] = size_[k];
    pushup(k);
    k = t;
  }

  void insert(int &k, int x) {  // 插入
    if (!k) {
      sz++;
      k = sz;
      size_[k] = 1;
      w[k] = 1;
      val[k] = x;
      rnd[k] = rand();
      return;
    }
    size_[k]++;
    if (val[k] == x) {
      w[k]++;
    } else if (val[k] < x) {
      insert(r[k], x);
      if (rnd[r[k]] < rnd[k]) lrotate(k);
    } else {
      insert(l[k], x);
      if (rnd[l[k]] < rnd[k]) rrotate(k);
    }
  }

  bool del(int &k, int x) {  // 删除节点
    if (!k) return false;
    if (val[k] == x) {
      if (w[k] > 1) {
        w[k]--;
        size_[k]--;
        return true;
      }
      if (l[k] == 0 || r[k] == 0) {
        k = l[k] + r[k];
        return true;
      } else if (rnd[l[k]] < rnd[r[k]]) {
        rrotate(k);
        return del(k, x);
      } else {
        lrotate(k);
        return del(k, x);
      }
    } else if (val[k] < x) {
      bool succ = del(r[k], x);
      if (succ) size_[k]--;
      return succ;
    } else {
      bool succ = del(l[k], x);
      if (succ) size_[k]--;
      return succ;
    }
  }

  int queryrank(int k, int x) {
    if (!k) return 0;
    if (val[k] == x)
      return size_[l[k]] + 1;
    else if (x > val[k]) {
      return size_[l[k]] + w[k] + queryrank(r[k], x);
    } else
      return queryrank(l[k], x);
  }

  int querynum(int k, int x) {
    if (!k) return 0;
    if (x <= size_[l[k]])
      return querynum(l[k], x);
    else if (x > size_[l[k]] + w[k])
      return querynum(r[k], x - size_[l[k]] - w[k]);
    else
      return val[k];
  }

  void querypre(int k, int x) {
    if (!k) return;
    if (val[k] < x)
      ans = k, querypre(r[k], x);
    else
      querypre(l[k], x);
  }

  void querysub(int k, int x) {
    if (!k) return;
    if (val[k] > x)
      ans = k, querysub(l[k], x);
    else
      querysub(r[k], x);
  }
} T;

int main() {
  srand(123);
    std::cin >>n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    for(int i=1;i<=n;i++){
        T.insert(T.rt,i);
    }
    for (int i=1;i<=n/2;i++){
        std::cin >>abb[i][0];
    }
    for (int i=1;i<=n/2;i++){
        std::cin >>abb[i][1];
    }
    for(int i=1;i<=n/2;i++){

            anss[i][0]=T.querynum(T.rt,abb[i][0]);
            T.del(T.rt,anss[i][0]);
            anss[i][1]=T.querynum(T.rt,abb[i][1]);
            T.del(T.rt,anss[i][1]);
    }
    for(int i=1;i<=n/2;i++){
        
        std::cout<<anss[i][0]<<" ";
    }std::cout<<std::endl;
    for(int i=1;i<=n/2;i++){
        std::cout<<anss[i][1]<<" ";
    }std::cout<<std::endl;
    //saada
  return 0;
}