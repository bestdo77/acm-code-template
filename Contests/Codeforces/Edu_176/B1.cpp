#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
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
int n,ans,k;
void Atomatic_AC_machine(){
    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==2){
        int mx=*max_element(a+1,a+1+n);
        if(a[1]!=mx&&a[n]!=mx){
            cout<<*max_element(a+2,a+n)+max(a[1],a[n])<<endl;
        }else{
            sort(a+1,a+1+n,greater<int>());
            cout<<accumulate(a+1,a+1+k,0ll)<<endl;
        }
    }else{
        sort(a+1,a+1+n,greater<int>());
            cout<<accumulate(a+1,a+1+k,0ll)<<endl;
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