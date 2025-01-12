#include <bits/stdc++.h>
using namespace std;
#define db double
const db eps = 1e-8;       // 根据题目精度要求进行修改
const db PI = acos(-1.0);  // pai, 3.1415916....

int sgn(db x) {  // 进行判断, 提高精度
    if (fabs(x) < eps)
        return 0;           // x == 0, 精度范围内的近似相等
    return x > 0 ? 1 : -1;  // 返回正负
}
bool eq(db a, db b) {
    return abs(a - b) < eps;
}  // ==
bool gt(db a, db b) {
    return a - b > eps;
}  // >
bool lt(db a, db b) {
    return a - b < -eps;
}  // <
bool ge(db a, db b) {
    return a - b > -eps;
}  // >=
bool le(db a, db b) {
    return a - b < eps;
}  // <=

// 点和向量<---------------------------------------------->
// Need: sgn()
typedef struct Point {
    db x, y;
    Point(db x = 0, db y = 0) : x(x), y(y) {}  // 构造函数, 初始值为 0

    // 重载运算符
    // 点 - 点 = 向量(向量AB = B - A)
    Point operator-(const Point& B) const { return Point(x - B.x, y - B.y); }

    // 点 + 点 = 点, 点 + 向量 = 向量, 向量 + 向量 = 向量
    Point operator+(const Point& B) const { return Point(x + B.x, y + B.y); }

    // 向量 × 向量 (叉积)
    db operator^(const Point& B) const { return x * B.y - y * B.x; }

    // 向量 · 向量 (点积)
    db operator*(const Point& B) const { return x * B.x + y * B.y; }

    // 点 * 数 = 点, 向量 * 数 = 向量
    Point operator*(const db& B) const { return Point(x * B, y * B); }

    // 点 / 数 = 点, 向量 / 数 = 向量
    Point operator/(const db& B) const { return Point(x / B, y / B); }

    // 判断大小, 一般用于排序
    bool operator<(const Point& B) const {
        return x < B.x || (x == B.x && y < B.y);
    }

    // 判断相等, 点 == 点, 向量 == 向量, 一般用于判断和去重
    bool operator==(const Point& B) const {
        return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
    }

    // 判断不相等, 点 != 点, 向量 != 向量
    bool operator!=(const Point& B) const {
        return sgn(x - B.x) || sgn(y - B.y);
    }
} Vector;

inline Point read_Point() {
    Point res;
    cin >> res.x >> res.y;
    return res;
}

// 两点间距离
// Need: (-, *)
db dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}

// 向量的模
// Need: (*)
db len(Vector A) {
    return sqrt(A * A);
}

// 单位向量
// Need: (/), len()
Vector norm(Vector A) {
    return A / len(A);
}

// 两向量夹角
// Need: (*), len(), PI
db Angle(Vector A, Vector B) {
    db t = acos((A * B) / len(A) / len(B));
    return t;               // 返回 [0, π]
    return t * (180 / PI);  // 返回 [0, 180] (角度)
}

// 两向量的夹角余弦
// Need: (*), len
db cos_t(Vector u, Vector v) {
    return u * v / len(u) / len(v);
}

// 将向量逆时针旋转90度
Vector r90a(Vector v) {
    return {-v.y, v.x};
}

// 将向量顺时针旋转90度
Vector r90c(Vector v) {
    return {v.y, -v.x};
}

// 将向量逆时针旋转
// Need: (*, ^)
// 向量 A 和要逆时针转的角度 [0, PI]
// PI / 2, 90度
Vector Rotate(Vector A, db b) {
    Vector B(sin(b), cos(b));
    return Vector(A ^ B, A * B);
}

// 向量是否互相垂直
// Need: (*), eq
bool verti(Vector u, Vector v) {
    return eq(u * v, 0);
}

// 向量是否互相平行
// Need: (^), eq
bool paral(Vector u, Vector v) {
    return eq(u ^ v, 0);
}

// 向量是否与x轴平行
// Need: eq
bool paral_x(Vector v) {
    return eq(v.y, 0);
}

// 向量是否与y轴平行
// Need: eq
bool paral_y(Vector v) {
    return eq(v.x, 0);
}
using Points = vector<Point>;
bool check(Point p, Point q, Point r) {
    return le(0, (q - p) ^ (r - q));
}
vector<Point> Andrew(Points poly) {  // 末尾额外塞了个头
    int n = poly.size(), top = 0;
    vector<int> stk(n + 2, 0), used(n + 2, 0);
    sort(poly.begin(), poly.end());
    stk[++top] = 0;
    for (int i = 1; i < n; i++) {
        while (top > 1 &&
               sgn((poly[stk[top]] - poly[stk[top - 1]]) ^
                   (poly[i] - poly[stk[top]])) <= 0)  // 去掉等号可以找共线的点
            used[stk[top--]] = 0;

        used[i] = 1;
        stk[++top] = i;
    }
    int tmp = top;
    for (int i = n - 2; i >= 0; i--) {
        if (used[i])
            continue;
        while (top > tmp && sgn((poly[stk[top]] - poly[stk[top - 1]]) ^
                                (poly[i] - poly[stk[top]])) <= 0)
            used[stk[top--]] = 0;

        used[i] = 1;
        stk[++top] = i;
    }
    vector<Point> a;
    for (int i = 1; i <= top; i++)
        a.push_back(poly[stk[i]]);
    return a;
}
db Dist_point_to_line(Point P, Point A, Point B) {
    // 点到直线距离
    Vector v1 = B - A, v2 = P - A;
    return fabs((v1 ^ v2) / len(v1));
}
db RoatingCalipers(vector<Point> poly) {  // 需要先求凸包，注意末尾塞个poly[0]
    if (poly.size() == 3)
        return len(poly[1] - poly[0]);
    int cur = 0, n = poly.size();
    db ans = 0;
    for (int i = 0; i < n - 1; i++) {
        while (Dist_point_to_line(poly[cur], poly[i], poly[i + 1]) <=
               Dist_point_to_line(poly[(cur + 1) % n], poly[i], poly[i + 1])) {
            cur = (cur + 1) % n;
        }
        ans = max(ans,
                  max(len(poly[i] - poly[cur]), len(poly[i + 1] - poly[cur])));
    }
    return ans;
}
const double INF = 1e18;
Points a;
double dis(int x, int y) {
    double dx = a[x].x - a[y].x;
    double dy = a[x].y - a[y].y;
    return dx * dx + dy * dy;
}
bool cmpx(const Point& x, const Point& y) {
    return x.x < y.x;
}

// 按 y 坐标排序的比较函数
bool cmpy(const int& x, const int& y) {
    return a[x].y < a[y].y;
}
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        db x,y; cin>>x>>y;
        a.emplace_back(Point(x,y));
    }
    sort(a.begin(),a.end(),cmpx);
    // cout<<fixed<<setprecision(10)<<sqrt(solve(0,n-1))<<" ";
    a.emplace_back(a[0]);
    a=Andrew(a);
    db maxdis=RoatingCalipers(a);
    cout<<(long long)(maxdis*maxdis)<<endl;
}