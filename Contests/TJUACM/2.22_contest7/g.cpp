#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=2e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
set<int> pos;
int ans[N];
void Atomatic_AC_machine(){
    int n=(1ll<<20);
    for(int i=1;i<=n;i++) ans[i]=-1;
    for(int i=0;i<2*n;i++){
        pos.insert(i);
    }
    int q;cin>>q;
    // cout<<q<<endl;
    for(int i=1;i<=q;i++){
        int op,x;cin>>op>>x;
        if(op==1){
            int h=x%n;
            int p=*pos.lower_bound(h);
            // db(p);
            if(p>=n) p-=n;
            ans[p]=x;
            pos.erase(p);
            pos.erase(p+n);
        }else{
            cout<<ans[x%n]<<endl;
        }
    }
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}