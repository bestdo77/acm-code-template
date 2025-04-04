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
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+2*n);
    vector<int> op;
    for(int i=1;i<=n;i++){
        op.push_back(a[2*n-i+1]);
        op.push_back(a[i]);
    }
    int need=0;
    for(int i=1;i<op.size()-1;i++){
        if(i%2==1) need+=op[i];
        else need-=op[i];
    }
    op.pop_back();
    for(auto x:op){
        cout<<x<<" ";
    }
    cout<<a[2*n]+a[n]-need<<" "<<a[n]<<endl;
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