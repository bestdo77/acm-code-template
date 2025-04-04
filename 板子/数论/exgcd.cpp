#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}

void exgcd(int &x,int &y,int a,int b){
    if(b==0) {x=1,y=0;return;}
    exgcd(x,y,b,a%b);
    int t=y;
    y=x-(a/b)*t,x=t;
}
void Atomatic_AC_machine(){
    int a,b,c;cin>>a>>b>>c;
    int x,y;
    if(c%__gcd(a,b)!=0){
        cout<<-1<<endl;
    }else{
        int g=__gcd(a,b);
        a/=g,b/=g,c/=g;
        exgcd(x,y,a,b);
        a*=c,b*=c;
        /*
            通解：(a,b)互质的情况
            x=x0+k*b
            y=y0-k*a
        */
       int mnx,mxx,mny,mxy;
        bool flag=1;
        if(x<=0){
            int k=-(x/b)+1;
            x+=k*b;
            y-=k*a;
            mnx=x;
            if(y<=0) flag=0;
        }
        if(y<=0){
            int k=-(x/a)+1;
            y+=k*a;
            x-=k*b;
            mny=y;
            if(x<=0) flag=0;
        }
        if(!flag) cout<<mnx<<" "<<mny<<endl;
        else{
            
        }
    }
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;  
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}