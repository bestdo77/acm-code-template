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
int vis[N];
int cnt[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    int cnt1=0;
    for(int i=1;i<=m;i++){
        int x;cin>>x;
        string s;cin>>s;
        if(s=="AC") vis[x]=1;
        else if(!vis[x]) cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) cnt1+=cnt[i];
    }
    cout<<accumulate(vis+1,vis+1+n,0)<<" "<<cnt1<<endl;
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