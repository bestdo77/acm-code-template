#include <bits/stdc++.h>
using namespace std;
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
void print(vector<int> a){for(auto it:a) db(it);cendl}
void pa(int *p,int n){for(int i=1;i<=n;i++){db(*(p+i))} cendl}

void Atomatic_AC_machine(){
    int n;
    n=read();
    int t=0;
    for(int i=1;i<=2*n+1;i++){
        int x;
        x=read();
        t^=x;
    }
    cout<<t<<endl;
}   
signed main(){
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}