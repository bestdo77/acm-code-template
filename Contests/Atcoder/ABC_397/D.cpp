#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define ll __int128
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
map<int,int> vis;
int ansd(int x){
    for(int i=1;i*i*i<=x;i++){
        if(i*i*i==x){
            return i;
        }
    }
}
void Atomatic_AC_machine(){
    ll x=1e8;
    // cout<<x*x*x<<endl;
    // cout<<
    cout<<(int)(x*x*x-(x-1)*(x-1)*(x-1))<<endl;
    // if(!flag) cout<<-1<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}