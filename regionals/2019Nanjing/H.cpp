#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define double long double
double eps = 1e-8;
class Point
{

public:
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}

    double operator ^(const Point &b)const{
        return x*b.y - b.x*y;
    }
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    }
    Point operator - (Point p){
        return Point(x - p.x , y - p.y);
    }
    bool operator == (const Point &p) const{
        return fabs(x - p.x)<1e-10&&fabs(y-p.y)<1e-10;
    }
    
}p[3];
typedef Point Vector;
double cross(Vector a,Vector b){
    return fabs(a.x*b.y - a.y*b.x);
}

int dcmp(double x){
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool onseg(Point p1,Point p2,Point q){
    return dcmp((p1 - q) ^ (p2 - q)) == 0&&dcmp((p1 - q)*(p2 - q)) <= 0;
}
double area(Point p0,Point p1,Point p2){
    double k = p0.x*p1.y + p1.x*p2.y + p2.x*p0.y - p1.x*p0.y - p2.x*p1.y - p0.x*p2.y;
    return fabs(k/2);
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>(b+c)){
        cout<<"YES"<<endl;
        if(a==1){
            cout<<0<<endl;
        }else cout<<2*(b+c)+1<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t -- ){
        solve();
    }
}