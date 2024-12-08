#include<iostream>
using namespace std;
#define ll long long 

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0) {x = 1,y = 0;return a;}
    ll r = exgcd(b,a % b,y,x);
    y -= x* (a / b);
    return r;
}//注意这要求ax+by=gcd(a,b),一般情况 c=k*gcd(a,b) ,求解后乘k即可

int main()
{
    //构造最小正整数解
    int r=exgcd(a,b,x,y);
    x=(x%(a*b/r) + (a*b/r)) % (a*b/r);
}               