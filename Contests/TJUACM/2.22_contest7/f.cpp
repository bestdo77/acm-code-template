#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
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
int vis[N];
int a[N];
int a1[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;cin>>u>>v>>w;
        a[i]=a1[i]=u+v+w;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int x=upper_bound(a+1,a+1+n,a1[i]+300)-a-1;
        if(n-x+1<=k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}