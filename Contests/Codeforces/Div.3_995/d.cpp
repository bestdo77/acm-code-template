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
int a[N];
void Atomatic_AC_machine(){
    int n,x,y;cin>>n>>x>>y;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    int ans=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int r=sum-a[i]-x;
        int l=sum-a[i]-y;
        int pos1=upper_bound(a+1,a+1+i-1,l-1)-a;
        int pos2=(upper_bound(a+1,a+1+i-1,r)-a);
        db(pos1<<" "<<pos2<<" "<<pos2-pos1)
        cendl
        ans+=pos2-pos1;
    }
    cout<<ans<<endl;
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