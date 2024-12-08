#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
const int N = 2e5;
struct point
{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
} a[N];
bool operator<(point a, point b) { return a.y < b.y; }
int main()
{
    int n;
    double d = 2e9;
    multiset<point> s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, [](point a, point b)
         { return a.x == b.x ? a.y < b.y : a.x < b.x; });
    for (int i = 0, j = 0; i < n; s.insert(a[i++]))
    {
        while (j < i && a[j].x <= a[i].x - d)
            s.erase(a[j++]);
        for (auto it = s.lower_bound(point(a[i].x, a[i].y - d)); it != s.end() && it->y < a[i].y + d; it++)
            d = min(d, hypot(a[i].x - it->x, a[i].y - it->y));
    }
    return printf("%.4lf", d), 0;
}