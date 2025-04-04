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
    for(int i=1;i<=n;i++) cin>>a[i];
    int lst=inf;
    for(int i=n;i-1>=1;i-=2){
        if(a[i]<a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(a[i]>lst){
            cout<<"NO"<<endl;
            return;
        }else{
            lst=a[i-1];
        }
    }
    if(n%2==1){
        if(a[1]>lst){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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