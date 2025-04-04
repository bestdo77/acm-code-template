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
map<int,int> ans;
pii circle[N];
int dis(int x,int op,int r){
    return sqrt(r*r-(x-op)*(x-op));
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>circle[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>circle[i].second;
    }
    for(int i=1;i<=n;i++){
        auto &[x,r]=circle[i];
        for(int op=x-r;op<=x+r;op++){
            ans[op]=max(ans[op],2*dis(x,op,r)+1);
        }
    }
    int ans1=0;
    for(auto &[_,cnt]:ans){
        ans1+=cnt;
    }
    cout<<ans1<<endl;
    ans.clear();
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