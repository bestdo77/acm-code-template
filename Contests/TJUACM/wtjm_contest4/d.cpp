#include <iostream>
#include <cmath>
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

db d[N1][N1];
int sgn(db x) {  // 进行判断, 提高精度
    if (fabs(x) < eps)
        return 0;           // x == 0, 精度范围内的近似相等
    return x > 0 ? 1 : -1;  // 返回正负
}
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
}Vector;
int Cross(Point a, Point b, Point c) {
    return sgn((b - a) ^ (c - a));
}
bool OnSegment(Point P, Point A, Point B) {
    Vector PA = A - P, PB = B - P;
    return sgn(PA ^ PB) == 0 &&
           sgn(PA * PB) <= 0;  // <=, 包括端点; <, 不包括端点
}
struct Seg {
    Point s, e;
    Seg() {}
    Seg(Point x, Point y) : s(x), e(y) {}
};
bool Intersect_seg(Point a, Point b, Point c, Point d) {
    // 第一个if是判断是否在端点处相交
    // if (OnSegment(a, c, d) || OnSegment(b, c, d) || OnSegment(c, a, b) ||
    //     OnSegment(d, a, b))
    //     return 1;
    if (Cross(a, b, c) * Cross(a, b, d) >= 0)
        return 0;
    if (Cross(c, d, a) * Cross(c, d, b) >= 0)
        return 0;
    return 1;
}
db dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n&&n!=-1){
        vector<Point> pi;
        vector<Seg> sg;
        pi.push_back(Point(0,5));
        for(int i=1;i<=n;i++){
            db x;cin>>x;
            db y1,y2,y3,y4;
            cin>>y1>>y2>>y3>>y4;
            Point O(x,0);
            Point a(x,y1);
            Point b(x,y2);
            Point c(x,y3);
            Point d(x,y4);
            Point E(x,10);
            pi.push_back(a);
            pi.push_back(b);
            pi.push_back(c);
            pi.push_back(d);
            sg.push_back(Seg(O,a));
            sg.push_back(Seg(b,c));
            sg.push_back(Seg(d,E));
        }
        pi.push_back(Point(10,5));
        for(int i=0;i<pi.size();i++){
            for(int j=i;j<pi.size();j++){
                if(i==j) {
                    d[i+1][j+1]=d[j+1][i+1]=0;
                    continue;
                }
                Seg nw(pi[i],pi[j]);
                bool check=0;
                for(int k=0;k<sg.size();k++){
                    if(Intersect_seg(nw.e,nw.s,sg[k].e,sg[k].s)){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        check=1;
                        break;
                    }
                }
                if(!check){
                    // cout<<i<<" "<<j<<endl;
                    d[j+1][i+1]=d[i+1][j+1]=dist(pi[i],pi[j]);
                }else d[j+1][i+1]=d[i+1][j+1]=inf;
            }
        }
        // for(int i=0;i<sg.size();i++){
        //     cout<<sg[i].e.x<<" "<<sg[i].e.y<<" "<<sg[i].s.x<<" "<<sg[i].s.y<<endl;
        // }
        int len=pi.size();
        for(int k=1;k<=len;k++){
            for(int i=1;i<=len;i++){
                for(int j=1;j<=len;j++){
                    d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
                }
            }
        }
        cout<<fixed<<setprecision(20)<<d[1][len]<<endl;            
    }
    return 0;
}