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
#define tii tuple<int,int,int>
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
pii a[N];
tii b[N];
tii c[N];
int pos[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    for(int i=1;i<=n;i++){
        b[i]={a[i].first,a[i].second,i};
        c[i]=b[i];
        pos[i]=i;
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n-1;i++){
        auto [_,x1,_]=b[i];
        auto [_,x2,_]=b[i+1];
        if(x2<x1){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(c[i]>c[j]){
                ans.push_back({i,j});
                swap(c[i],c[j]);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans){
        cout<<u<<" "<<v<<endl;
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