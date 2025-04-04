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
int presum[N],prexor[N];
int cal(int l,int r){
    return (presum[r]-presum[l-1])-(prexor[r]^prexor[l-1]);
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        presum[i]=presum[i-1]+a[i];
        prexor[i]=prexor[i-1]^a[i];
    }
    int l,r;
    cin>>l>>r;
    int ansl=l,ansr=r;
    int ans=cal(l,r);
    int j=l;
    for(int i=l;i<=r;i++){
        if(j<i) j=i;
        while(j<r&&cal(i,j)<ans){
            j++;
        }
        if(cal(i,j)==ans){
            if(j-i+1<ansr-ansl+1){
                ansl=i,ansr=j;
            }
        }
    }
    cout<<ansl<<" "<<ansr<<endl;

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