#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template<typename T>
struct Comb {
    int n;
    std::vector<T> _fac;     // 阶乘
    std::vector<T> _invfac;  // 逆阶乘
    std::vector<T> _inv;     // 逆元

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    // 初始化阶乘、逆阶乘和逆元
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    // 返回阶乘 n!
    T fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }

    // 返回逆阶乘 1/(n!)
    T invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }

    // 返回逆元 1/n
    T inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }

    // 返回组合数 C(n, m)
    T binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
};