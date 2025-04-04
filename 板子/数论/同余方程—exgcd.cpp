#include<iostream>
using namespace std;
#define ll long long 
ll t,c,d,x,y;

void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);y-=(a/b)*x;
}
//什么是同余方程？ax≡1(modb)就是ax除以b的余数等于1,求最小的x,x就是a的逆元。 
int main()
{
    ll c,d;//c是a，d是moshu
    cin>>c>>d;
    exgcd(c,d,x,y);//一定有解就不用管xy初始的值。 
    while(x<=0){
        x+=d;
    }//最小正整数解保证是正数 
    cout<<x<<endl;
    return 0;
}                                                                                                                                                 