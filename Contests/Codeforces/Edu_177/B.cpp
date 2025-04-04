#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
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
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    i64 n,k,x;cin>>n>>k>>x;
    vector<i64> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    i64 cnt=n*k;
    i64 sum=accumulate(a.begin(),a.end(),0ll);
    i64 duan=min(k,x/sum);
    if(duan*sum==x){
        cnt++;
    }
    x-=duan*sum;
    cnt-=n*duan;
    if(duan<k){
        for(int i=n-1;i>=0;i--){
            if((x-a[i])<=0) break;
            x-=a[i];
            cnt--;
        }
    }
        
    cout<<cnt<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}