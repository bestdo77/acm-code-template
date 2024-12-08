#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
typedef long long ll ;
inline void print(int x){
if(x < 0) putchar('-'), x = -x;
if(x > 9) print(x / 10);
putchar(x % 10 + '0');
return ;
}
int sqr(int x){
    long double tem=x;
    __int128_t res=sqrt(tem);
    __int128_t a0=0;
    res-=100;
    res=max(res,a0);
    while (res*res<=x){
        //cout <<(ll)res<<endl;
        res++;
    }
    res--;
    return res;
}
bool fingfa(__int128_t x)//开方
{
    __int128_t y=(__int128_t)ceil(sqrt((long double)x));
    for(;y*y<=x;++y);
        for(--y;y*y>x;--y);
    return y*y==x;
}
int nn(int l,int r,int n){
    int ls=sqr(l);
    int rs=sqr(r);
    int ans=0;
    int low=1;
    int high=9;
    for(int i=1;i<n;i++) high*=10,high+=9;
    for(int i=1;i<n;i++) low*=10;
    ans+=((ls+(int)(fingfa(l)? 0:1))-sqr(low)-(int)( fingfa(low)? 0 : 1))*(sqr(high)+1);
    //cout<<(ll)ans<<endl;
    if(fingfa(l)) {
        ans+=rs+1;
    }
    //cout<<(ll)ans<<endl;
    return ans;
}


void solve(){
    signed n;
    cin>>n;
    string l;
    string r;
    cin>>l>>r;
    int l1=0,l2=0,r1=0,r2=0;
    for(signed i=0;i<n/2;i++){
        l1*=10;
        l1+=l[i]-'0';
        r1*=10;
        r1+=r[i]-'0';
    }
    for(signed i=n/2;i<n;i++ ){
        l2*=10;
        l2+=l[i]-'0';
        r2*=10;
        r2+=r[i]-'0';
    }
    int ans=nn(r1,r2,n/2)-nn(l1,l2,n/2)+(int)(fingfa(l1)&fingfa(l2));
    print(ans);
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }


    return 0;
}