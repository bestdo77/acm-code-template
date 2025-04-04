#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    int ans=0;
    for(int i=0;i<=30;i++){
        int dec=(1ll<<i);
        if(l1&dec) ans+=(r2-l2)/dec,l1+=dec;
        if(l1==r1) break;
        if(r1&dec) ans+=(r2-l2)/dec,r1-=dec;   
        if(l1==r1) break;
        if(l2&dec) ans+=(r1-l1)/dec,l2+=dec;
        if(l2==r2) break;
        if(r2&dec) ans+=(r1-l1)/dec,r2-=dec;
        if(l2==r2) break;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}