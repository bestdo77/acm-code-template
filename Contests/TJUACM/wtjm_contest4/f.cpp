// 凸包
// Andrew算法求凸包，最后一个点与第一个点重合
// Need: (^,-,<), sgn, le
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
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
typedef struct Point {
    db x, y,v,l,id;
    Point(db x = 0, db y = 0 , db v = 0 , db l = 0 , db id = 0) : x(x), y(y), v(v), l(l), id(id) {}  // 构造函数, 初始值为 0

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
db dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}
bool check(Point p, Point q, Point r) {
    return le(0, (q - p) ^ (r - q));
}
db Andrew(vector<Point>& poly) {  // 末尾额外塞了个头
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
    db sum=0;
    for(int i=1;i<a.size();i++){
        sum+=dist(a[i],a[i-1]);
    }
    sum+=dist(a[0],a.back());
    return sum;
}
bool cmp1(Point x,Point y){
    return x.id<y.id;
}
signed main(){
    int n;
    int id=0;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int flag=0;
    while(cin>>n&&n){
        if(flag++) cout<<endl;
        vector<Point> pi;
        for(int i=1;i<=n;i++){
            int x,y,v,l;
            cin>>x>>y>>v>>l;
            pi.push_back(Point(x,y,v,l,i));
        }
        db ans=inf;
        db anscost=inf;
        vector<Point> ansP;
        for(int i=0;i<(1<<n);i++){
            vector<Point> poly;
            vector<Point> rest;
            db hv=0,hl=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                }else{
                    hv+=pi[j].v;
                    hl+=pi[j].l;
                }
            }
            if(hv-anscost>eps){
                continue;
            }
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    poly.push_back(pi[j]); 
                }
            }
            if(!poly.size()) continue;
            db cost=Andrew(poly);
            if(hl-cost>eps&&anscost-hv>eps){
                for(int j=0;j<n;j++){
                    if(!(i&(1<<j))){
                        rest.push_back(pi[j]); 
                    }
                }
                ans=hl-cost;
                anscost=hv;
                ansP=rest;
            }else if(hl-cost>eps&&anscost-hv<=eps){
                for(int j=0;j<n;j++){
                    if(!(i&(1<<j))){
                        rest.push_back(pi[j]); 
                    }
                }
                if(ansP.size()>rest.size())ansP=rest;
            }
        }
        id++;
        cout<<"Forest "<<(int)id<<endl;
        cout<<"Cut these trees:";
        sort(ansP.begin(),ansP.end(),cmp1);
        for(int i=0;i<ansP.size();i++){
            cout<<" "<<(int)ansP[i].id;
        }
        cout<<endl;
        cout<<fixed<<setprecision(2)<<"Extra wood: "<<ans<<endl;
    }
}