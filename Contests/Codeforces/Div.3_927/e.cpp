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

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int a[N];
int b[N],p;
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        char x;cin>>x;
        a[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[n-i+1];
    }
    for(int i=1;i<=n;i++){
        db(a[i])
    }
    cendl
    int p=1;
    while(b[p]){
        b[p+1]+=b[p]/10;
        b[p]=b[p]%10;
        p++;
    }
    for(int i=p-1;i>=1;i--){
        cout<<b[i];
    }
    cout<<endl;
    for(int i=1;i<=p;i++){
        a[i]=b[i]=0;
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