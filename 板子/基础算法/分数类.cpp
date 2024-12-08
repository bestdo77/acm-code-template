#include <bits/stdc++.h>
#define int long long
using namespace std;
// using int = long long;
struct frac
{
    int num, den;
    frac() : num(0), den(1) {}
    frac(int val)
    {
        num = val;
        den = 1;
    }
    frac(int a, int b)
    {
        int g = gcd(a, b);
        num = a / g;
        den = b / g;
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
    }
};
frac operator+(frac x, frac y){
    return frac(x.num * y.den + y.num * x.den, x.den * y.den);
}
frac operator-(frac x, frac y){
    return frac(x.num * y.den - y.num * x.den, x.den * y.den);
}
frac operator*(frac x, frac y){
    return frac(x.num * y.num, x.den * y.den);
}
frac operator/(frac x, frac y){
    return frac(x.num * y.den, x.den * y.num);
}
frac operator+(frac x, int val){
    return frac(x.num + x.den * val, x.den);
}
frac operator*(frac x, int val){
    return frac(x.num * val, x.den);
}
frac operator/(frac x, int val){
    return frac(x.num, x.den * val);
}
bool operator==(frac x, frac y){
    return x.num == y.num && x.den == y.den;
}
bool operator!=(frac x, frac y){
    return x.num != y.num || x.den != y.den;
}
bool operator<(frac x, frac y){
    return x.num * y.den < y.num * x.den;
}
frac abs(frac x){
    if (x.num < 0)
        return frac(-x.num, x.den);
    return x;
}
int main()
{
    printf("%d\n", gcd(0, 6));
    return 0;
}