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
vector<int> con(int x,int n){
    vector<int> res;
    while(x){
        res.push_back(x%4);
        x/=4;
    }
    while(res.size()<n){
        res.push_back(0);
    }
    return res;
}
set<int> a1,a2;
void Atomatic_AC_machine(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a1.insert(x);
    }
    for(int i=1;i<=m;i++){
        int x;cin>>x;
        a2.insert(x);
    }
    for(int i=1;i<=q;i++){
        int l1=inf,r1=inf,l2=inf,r2=inf;
        int ans=inf;
        int x;cin>>x;
        if(a1.lower_bound(x)!=a1.end())  r1=*a1.lower_bound(x);
        if(a2.lower_bound(x)!=a2.end())  r2=*a2.lower_bound(x);
        if(a1.lower_bound(x)!=a1.begin()) l1=*prev(a1.lower_bound(x));
        if(a2.lower_bound(x)!=a2.begin()) l2=*prev(a2.lower_bound(x));
        db(l1<<" "<<l2<<" "<<r1<<" "<<r2)
        cendl
        if(l1!=inf&&l2!=inf) ans=min(ans,x-min(l1,l2));
        if(l1!=inf&&r2!=inf) ans=min(ans,min(r2-x,x-l1)+r2-l1);
        if(r1!=inf&&l2!=inf) ans=min(ans,min(r1-x,x-l2)+r1-l2);
        if(r1!=inf&&r2!=inf) ans=min(ans,max(r1,r2)-x);
        cout<<ans<<endl;
    }
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