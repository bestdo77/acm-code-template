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
    for(int i = 0;i<3;i++){
            cin>>p[i].x>>p[i].y;
        }
        int x,y;
        cin>>x>>y;
        Point Q(x,y);
        for(int i = 0;i<3;i++){
            if(Q == p[i]){
                cout<<fixed<<setprecision(10)<<(p[(i+1)%3].x+p[((i+2)%3)].x)/2<<" "<<
                (p[(i+1)%3].y+p[((i+2)%3)].y)/2<<endl;
                return;
            }
        }
        double ans = area(p[0],p[1],p[2])/2;
        for(int i = 0;i<3;i++){
            if(onseg(p[(i+1)%3],p[(i+2)%3],Q)){
                Point ll = p[(i+1)%3] ,rr = p[(i+2)%3];
                if(area(ll,p[i],Q) < area(rr,p[i],Q)){
                    //rbian
                    Point l = p[i],r = rr;
                    int cnt = 0;
                    while(++cnt){
                        Point mid((l.x+r.x)/2,(l.y+r.y)/2);
                        if(fabs(area(Q,mid,rr) - ans)<eps){
                            
                            cout<<fixed<<setprecision(10)<<mid.x<<" "<<mid.y<<endl;
                            return;
                        }
                        //cout<<area(Q,mid,rr)<<endl;
                        if(area(Q,mid,rr) > ans) l = mid;
                        else r = mid;
                        if(cnt == 100){
                            cout<<fixed<<setprecision(10)<<mid.x<<" "<<mid.y<<endl;
                            return;
                        }

                    }
                    
                }
                else{
                    Point l = p[i],r = ll;
                    int cnt = 0;
                    while(++cnt){
                        Point mid((l.x+r.x)/2,(l.y+r.y)/2);
                        if(fabs(area(Q,mid,ll) - ans)<eps){
                            cout<<fixed<<setprecision(10)<<mid.x<<" "<<mid.y<<endl;
                            return;
                        }
                        if(area(Q,mid,ll) > ans) l = mid;
                        else r = mid;
                        if(cnt == 100){
                            cout<<fixed<<setprecision(10)<<mid.x<<" "<<mid.y<<endl;
                            return;
                        }
                    }
                }
            }
            else continue;
        }
        cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t -- ){
        solve();
    }
}