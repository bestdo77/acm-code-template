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

int p[N],p1[N],p2[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>p1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p2[i];
    }
    int cnt1=1;
    int cnt2=1;
    int cnt=1;
    do{
        bool flag1=1,flag2=1;
        for(int i=1;i<=n;i++){
            if(p[i]!=p1[i]) flag1=0;
        }
        for(int i=1;i<=n;i++){
            if(p[i]!=p2[i]) flag2=0;
        }
        if(flag1) cnt1=cnt;
        if(flag2) cnt2=cnt;
        cnt++;
    }while(next_permutation(p+1,p+1+n));
    cout<<abs(cnt1-cnt2)<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}