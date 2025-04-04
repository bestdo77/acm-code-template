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
void Atomatic_AC_machine(){
    priority_queue<int> pq;
    int n,k;cin>>n>>k;
    vector<int> a(k+1,0),pre(k+1,0),suf(k+3,0);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(k%2==1){
        for(int i=1;i<=k;i++){
            if(i%2==0){
                pre[i]=pre[i-2]+a[i]-a[i-1];
            }
        }
        for(int i=k-1;i>=1;i-=2){
            suf[i]=suf[i+2]+a[i+1]-a[i];
        }
        int ans=inf;
        for(int i=1;i+2<=k;i++){
            if(i%2==1){
                ans=min(ans,pre[i-1]+suf[i+3]+a[i+2]-a[i]);
            }
        }
        if(ans==inf) cout<<0<<endl;
        else cout<<ans<<endl;
    }else{
        int ans=0;
        for(int i=2;i<=k;i+=2){
            ans+=a[i]-a[i-1];
        }
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