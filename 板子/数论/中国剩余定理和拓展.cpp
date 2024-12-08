#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0) {x = 1,y = 0;return a;}
    ll r = exgcd(b,a % b,y,x);
    y -= x* (a / b);
    return r;
}
//x 三 r[i] (mod m[i])
ll crt(ll m[],ll r[],int n){
    ll M = 1, ans = 0;
    for(int i = 1;i <= n;i++) M *= m[i];
    for(int i = 1;i <= n;i++){
        ll c = M / m[i] ,x,y;
        exgcd(c, m[i], x, y);//求逆元
        ans = (ans + r[i]* c* x%M) % M;
    }
    return (ans % M + M)% M;
}

ll excrt(ll m[],ll r[],int n){
    ll m1,m2,r1,r2,p,q;
    m1 = m[1],r1 = r[1];
    for(int i = 2;i <= n;i++){
        m2 = m[i],r2 = r[i];
        ll d = exgcd(m1,m2,p,q);
        if((r2-r1) % d)  return -1;
        p = p * (r2-r1) /d;//特解
        p = (p % (m2/d) + m2/d) % (m2/d);
        r1 = m1*p + r1;
        m1 = m1*m2/d;
    }
    return (r1%m1+m1)%m1;
}