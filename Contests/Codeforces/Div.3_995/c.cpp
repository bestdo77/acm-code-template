#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// #define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int a[N],ok[N];
void Atomatic_AC_machine(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>ok[i];
    if(n-k>=2){
        for(int i=1;i<=m;i++){
            cout<<0;
        }
        cout<<endl;
        return;
    }else if(n==k){
        for(int i=1;i<=m;i++){
            cout<<1;
        }
        cout<<endl;
        return;
    }else{
        int mn=1;
        for(int i=1;i<=k;i++){
            if(ok[i]==mn) mn++;
        }
        db(mn)
        cendl
        for(int i=1;i<=m;i++){
            cout<<(a[i]==mn?1:0);
        }
        cout<<endl;
    }
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