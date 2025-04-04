#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    i64 k,b,c,v;cin>>k>>b>>c>>v;
    i64 l=0,r=(v+c-b)/k+1,ans=0;
    for(int j=62;j>=0;j--){
        if(l>r) break;   
        i64 l1=l-1,r1=r+1;
        while(l1+1<r1){//只找(k*mid+b)的这一位啥时候是1
            i64 mid=l1+r1>>1;
            if((k*mid+b)&(1ll<<j)) r1=mid;
            else l1=mid;
        }
        i64 p=r1;
        if((1ll<<j)&v){//v的这一位是1，可以直接加上(k*x+b)^c为0的贡献
            if((1ll<<j)&c){//c的这一位是1，k*mid+b必须得是0,才能接下来走
                //加上k*mid+b为1的结果
                ans+=r-p+1;
                //此时k*mid+b为0;
                r=p-1;
            }else{
                ans+=p-l;
                l=p;
            }
        }else{//v的这一位是0，(k*x+b)^c只能是0
            if((1ll<<j)&c){//c是1,k*x+b是1
                l=p;
            }else{
                r=p-1;
            }
        }
    }
    if(l<=r) ans+=r-l+1;
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}