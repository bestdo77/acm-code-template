#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 5;
const double INF = 1e18;

struct Point {
    double x, y;
} a[N];

// 计算两点之间的距离的平方
double dis(int x, int y) {
    double dx = a[x].x - a[y].x;
    double dy = a[x].y - a[y].y;
    return dx * dx + dy * dy;
}

// 按 x 坐标排序的比较函数
bool cmpx(const Point& x, const Point& y) {
    return x.x < y.x;
}

// 按 y 坐标排序的比较函数
bool cmpy(const int& x, const int& y) {
    return a[x].y < a[y].y;
}

// 分治法求解最近点对
double solve(int l, int r) {
    if (l == r) return INF; // 只有一个点，返回无穷大
    if (l + 1 == r) return dis(l, r); // 只有两个点，直接返回距离

    int mid = (l + r) >> 1;
    double res = min(solve(l, mid), solve(mid + 1, r)); // 递归求解左右两部分

    // 筛选中间区域的点
    vector<int> vec;
    double sqrt_res = sqrt(res);
    for (int i = l; i <= r; i++) {
        if (fabs(a[mid].x - a[i].x) < sqrt_res) {
            vec.emplace_back(i);
        }
    }

    // 按 y 坐标排序
    sort(vec.begin(), vec.end(), [](int x, int y) {
        return a[x].y < a[y].y;
    });

    // 检查中间区域的点对
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size() && (a[vec[j]].y - a[vec[i]].y) < sqrt_res; j++) {
            res = min(res, dis(vec[i], vec[j]));
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    // 按 x 坐标排序
    sort(a, a + n, cmpx);

    // 输出最近点对的距离
    cout << fixed << setprecision(10) << sqrt(solve(0, n-1)) << endl;

    return 0;
}