#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const double pi=acos(-1.0);
const double eps=1e-8;

int sgn(double x){
    if (fabs(x)<=eps)   return 0;
    else if (x>0)   return 1;
    else    return -1;
}

int N;

struct Point{
    int x,y;
    Point(){}
    Point(double a,double b){
        x=a,y=b;
    }
    Point operator + (const Point &b) const{
        return Point(x+b.x,y+b.y);
    }
    Point operator - (const Point &b) const{
        return Point(x-b.x,y-b.y);
    }
    int operator * (const Point &b) const{
        return x*b.x+y*b.y;
    }
    int operator ^ (const Point &b) const{
        return x*b.y-y*b.x;
    }
    int len(){
        return x*x+y*y;
    }
}point[50010];

int Stack[50010],top;

double dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a,Point b){
    double tmp=(a-point[0])^(b-point[0]);
    if (sgn(tmp)>0) return true;
    else if (sgn(tmp)==0&&sgn(dist(a,point[0])-dist(b,point[0]))<=0)
        return true;
    else
        return false;
}

void Graham(int n){
    Point p0;
    int k=0;
    p0=point[0];
    for (int i=1;i<n;i++){
        if ((p0.y>point[i].y)||(p0.y==point[i].y&&p0.x>point[i].x)){
            p0=point[i];
            k=i;
        }
    }
    swap(point[k],point[0]);
    sort(point+1,point+n,cmp);
    if (n==1){
        top=1;
        Stack[0]=0;
        return;
    }
    if (n==2){
        top=2;
        Stack[0]=0;
        Stack[1]=1;
        return;
    }
    Stack[0]=0;
    Stack[1]=1;
    top=2;
    for (int i=2;i<n;i++){
        while (top>1&&sgn((point[Stack[top-1]]-point[Stack[top-2]])^(point[i]-point[Stack[top-2]]))<=0)
            top--;
        Stack[top++]=i;
    }
}

int rotating_calipers(){
    int q=1;
    int ans=0;
    Stack[top]=0;
    for (int i=0;i<top;i++){
        while (((point[Stack[i+1]]-point[Stack[i]])^(point[Stack[q+1]]-point[Stack[i]]))>((point[Stack[i+1]]-point[Stack[i]])^(point[Stack[q]]-point[Stack[i]])))
            q=(q+1)%top;
        ans=max(ans,max((point[Stack[i]]-point[Stack[q]]).len(),(point[Stack[i+1]]-point[Stack[q+1]]).len()));
    }
    return ans;
}

int main(){
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d %d",&point[i].x,&point[i].y);
    }
    Graham(N);
    int ans=rotating_calipers();
    printf("%d\n",ans);
}