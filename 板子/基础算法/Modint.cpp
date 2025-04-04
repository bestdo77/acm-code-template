#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template<u32 P>
struct ModInt {
public:
    constexpr ModInt() : x(0) {}
    template<std::unsigned_integral T>
    constexpr ModInt(T x_) : x(x_ % mod()) {}
    template<std::signed_integral T>
    constexpr ModInt(T x_) {
        using S = std::make_signed_t<u32>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }

    constexpr static u32 mod() {
        return P;
    }

    constexpr u32 val() const {
        return x;
    }

    constexpr ModInt operator-() const {
        ModInt res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }

    constexpr ModInt inv() const {
        return power(*this, mod() - 2);
    }

    constexpr ModInt &operator*=(const ModInt &rhs) & {
        x = mulMod(x, rhs.val());
        return *this;
    }
    constexpr ModInt &operator+=(const ModInt &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream &operator>>(std::istream &is, ModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val() <=> rhs.val();
    }

private:
    u32 x;

    constexpr static u32 mulMod(u32 a, u32 b) {
        return u64(a) * b % P;
    }

    constexpr static ModInt power(ModInt a, u64 b, ModInt res = 1) {
        for (; b != 0; b /= 2, a *= a) {
            if (b & 1) {
                res *= a;
            }
        }
        return res;
    }
};

using Z = ModInt<998244353>;  // 定义模数为 998244353 的 ModInt 类型