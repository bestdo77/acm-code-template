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
int a[N];
int sum1[N],sum2[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum2[n+1]=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1];
        if(a[i]>0) sum1[i]=sum1[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        sum2[i]=sum2[i+1];
        if(a[i]<0) sum2[i]=sum2[i+1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(sum1[i]+abs(sum2[i]),ans);
    }
    cout<<ans<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}