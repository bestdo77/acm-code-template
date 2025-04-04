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
int n,k;
int l[N],r[N];
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(l+1,l+1+n);
    sort(r+1,r+1+n);
    vector<int> q;
    for(int i=1;i<=n;i++){
        q.push_back(l[i]);
        q.push_back(r[i]);
    }
    int ans=0;
    for(auto x:q){
        int buy=r+1+n-lower_bound(r+1,r+1+n,x);
        int cha=l+1+n-lower_bound(l+1,l+1+n,x);
        db(x<<" "<<buy<<" "<<cha)
        cendl
        if(buy-cha<=k) ans=max(ans,buy*x);
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