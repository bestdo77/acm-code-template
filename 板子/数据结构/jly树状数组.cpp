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