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
multiset<int> a1,b1;
int a[N],b[N],vis[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    a[1]=1;
    for(int i=1;i<=n;i++) vis[i]=0;
    a1.clear();b1.clear();
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int j=upper_bound(b+1,b+1+n,a[i])-b;
        for(int p=j;p<=n;p++){
            if(!vis[p]){
                vis[p]=1;
                cnt++;
                break;
            }
        }
    }
    cout<<n-cnt<<endl;
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