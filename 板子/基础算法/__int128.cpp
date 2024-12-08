#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while (c<'0' || c>'9'){
        if (c=='-')  f=-1;
        c=getchar();
    }
    while (c>='0' && c<='9'){
        x=x*10+c-'0';
         c=getchar();
    }
    return x*f;
}
inline void print(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
    return ;
}
bool issqr(__int128_t x)//判断是不是平方数
{
    __int128_t y=(__int128_t)ceil(sqrt((long double)x));
    for(;y*y<=x;++y);
        for(--y;y*y>x;--y);
    return y*y==x;
}