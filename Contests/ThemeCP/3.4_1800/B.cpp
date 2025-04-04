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
int a[N],b[N],c[N];
int prea[N],preb[N],prec[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        prea[i]=prea[i-1]+a[i];
        preb[i]=preb[i-1]+b[i];
        prec[i]=prec[i-1]+c[i];
    }
    int lim=(accumulate(a+1,a+1+n,0ll)/3+!!(accumulate(a+1,a+1+n,0ll)%3));
    db(lim)
    cendl
    int la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(prea[ra]-prea[la-1]<lim){
            ra++;
        }else if(preb[rb]-preb[lb-1]<lim){
            rb++;
        }
        lb=ra+1;
        if(rb<lb) rb=lb;
        lc=rb+1;
        if(rc<lc) rc=lc;
    }
    rc=n;
    if(prec[rc]-prec[lc-1]>=lim&&lc<=n){
        db(1)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }
    
    la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(prea[ra]-prea[la-1]<lim){
            ra++;
        }else if(prec[rc]-prec[lc-1]<lim){
            rc++;
        }
        lc=ra+1;
        if(rc<lc) rc=lc;
        lb=rc+1;
        if(rb<lb) rb=lb;
    }
    rb=n;
    if(preb[rb]-preb[lb-1]>=lim&&lb<=n){
        db(2)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }

    la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(preb[rb]-preb[lb-1]<lim){
            rb++;
        }else if(prea[ra]-prea[la-1]<lim){
            ra++;
        }
        la=rb+1;
        if(ra<la) ra=la;
        lc=ra+1;
        if(rc<lc) rc=lc;
    }
    rc=n;
    if(prec[rc]-prec[lc-1]>=lim&&lc<=n){
        db(3)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }

    la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(preb[rb]-preb[lb-1]<lim){
            rb++;
        }else if(prec[rc]-prec[lc-1]<lim){
            rc++;
        }
        lc=rb+1;
        if(rc<lc) rc=lc;
        la=rc+1;
        if(ra<la) ra=la;
    }
    ra=n;
    if(prea[ra]-prea[la-1]>=lim&&la<=n){
        db(4)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }

    la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(prec[rc]-prec[lc-1]<lim){
            rc++;
        }else if(prea[ra]-prea[la-1]<lim){
            ra++;
        }
        la=rc+1;
        if(ra<la) ra=la;
        lb=ra+1;
        if(rb<lb) rb=lb;
    }
    rb=n;
    if(preb[rb]-preb[lb-1]>=lim&&lb<=n){
        db(5)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }
    
    la=1,ra=1,lb=1,rb=1,lc=1,rc=1;
    for(int i=1;i<=n;i++){
        if(prec[rc]-prec[lc-1]<lim){
            rc++;
        }else if(preb[rb]-preb[lb-1]<lim){
            rb++;
        }
        lb=rc+1;
        if(rb<lb) rb=lb;
        la=rb+1;
        if(ra<la) ra=la;
    }
    ra=n;
    if(prea[ra]-prea[la-1]>=lim&&la<=n){
        db(6)
        cendl
        cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
        return;
    }
    cout<<-1<<endl;
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