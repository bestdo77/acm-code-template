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
int b[N],w[N],pre1[N],pre2[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    sort(b+1,b+1+n,greater<int>());
    sort(w+1,w+1+m,greater<int>());
    for(int i=1;i<=n;i++){
        pre1[i]=pre1[i-1]+b[i];
    }
    for(int i=1;i<=m;i++){
        pre2[i]=pre2[i-1]+w[i];
    }
    int mx=*max_element(pre1+1,pre1+1+n);
    int p=max_element(pre1+1,pre1+1+n)-pre1;
    int ans=0;
    for(int i=0;i<=m;i++){
        if(i>n) break;
        if(i<=p) ans=max(ans,pre2[i]+mx);
        else ans=max(ans,pre1[i]+pre2[i]);
    }
    cout<<ans<<endl;
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