#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
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
int a[N];
int pre[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    for(int i=2;i<=m;i++){
        if(a[i]>=n){
            int pos1=upper_bound(a+1,a+1+m,n-2)-a;
            ans+=2*(n-1)*(i-pos1);
            ans+=2*(pre[pos1-1]);
        }else{
            int pos1=upper_bound(a+1,a+1+m,n-a[i]-1)-a;
            if(pos1>=i) continue;
            int cnt=i-pos1;
            ans+=2*(a[i]*cnt+pre[i-1]-pre[pos1-1]-(n-1)*cnt);
        }
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