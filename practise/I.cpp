#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);

int n,m;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}

    //向量+
    Point operator +(const Point &b)const
    {
        return Point(x+b.x,y+b.y);
    }
    //向量-
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    //点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    //叉积
    //P^Q>0,P在Q的顺时针方向；<0，P在Q的逆时针方向；=0，P，Q共线，可能同向或反向
    double operator ^(const Point &b)const
    {
        return x*b.y - b.x*y;
    }
}polygon[105];
typedef Point Vector;
double dis(double x0,double y0,double x1,double y1,double x2 ,double y2){
        double res,a,b,c;//以双精度保存变量
		cin>>x1>>y1>>x2>>y2>>x0>>y0;//输入三组数据
		a=(x0-x1)*(y2-y1);//分子的左半部分
		b=(y0-y1)*(x1-x2);//分子的右半部分
		c=a+b;//二者相加
		c*=c;//平方(pow(c,2)貌似在这里更加麻烦)
		a=pow(y2-y1,2);//分母左半部分
		b=pow(x1-x2,2);//分母右半部分
		c/=(a+b);//分子分母相除
		res=sqrt(c);//开方
		return res;
}
//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

//判断点Q是否在P1和P2的线段上
bool OnSegment(Point P1,Point P2,Point Q)
{
    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
}

//判断点P在多边形内-射线法
bool InPolygon(Point P)
{
    bool flag = false;
    Point P1,P2; //多边形一条边的两个顶点
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[i];
        P2 = polygon[j];
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
        if( (dcmp(P1.y-P.y)>0 != dcmp(P2.y-P.y)>0) && dcmp(P.x - (P.y-P1.y)*(P1.x-P2.x)/(P1.y-P2.y)-P1.x)<0)
            flag = !flag;
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
    Point test;
    while (m--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        test.x = 1.0*(x1+x2)/2;
        test.y = 1.0*(y1+y2)/2;
        int r = sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y2-y1)*(y2-y1))/2;
        int R;
        if (InPolygon(test))
            R = 0;
        else{

        }
    }

    return 0;
}
