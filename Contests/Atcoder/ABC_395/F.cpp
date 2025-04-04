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
int n,x;
int h[N],d[N];
bool check(int H){
    int l=max(0ll,H-d[1]),r=min(h[1],H);
    for(int i=2;i<=n;i++){
        int mx=min(h[i],H);
        int mn=max(0ll,H-d[i]);
        l-=x;
        r+=x;
        l=max(0ll,l);
        if(l>mx||r<mn) return 0;
        l=max(l,mn);
        r=min(r,mx);
    }
    return 1;
}
void Atomatic_AC_machine(){
    cin>>n>>x;
    int mn=inf;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>d[i];
        mn=min(mn,h[i]+d[i]);
    }
    int l=-1,r=mn+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    int cost=0;
    for(int i=1;i<=n;i++){
        cost+=h[i]+d[i]-l;
    }    
    cout<<cost<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}