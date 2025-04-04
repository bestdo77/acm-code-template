#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
void pa(int *p,int n){for(int i=1;i<=n;i++){db(*(p+i))} cendl}
int p[N],t[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    int mxid=max_element(t+1,t+1+n)-t;
    int mxp=p[mxid],mxt=t[mxid];
    for(int i=1;i<=n;i++){
        if(p[i]<=mxp){
            p[i]+=min(mxp-p[i],mxt-t[i]);
        }else{
            p[i]-=min(p[i]-mxp,mxt-t[i]);
        }
    }
    sort(p+1,p+1+n);
    double ans=p[1]+p[n];
    ans/=2;
    cout<<fixed<<setprecision(10)<<ans<<endl;
    
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }  
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}