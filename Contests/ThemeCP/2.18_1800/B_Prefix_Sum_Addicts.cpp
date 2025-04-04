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
int pre[N];
int a[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>pre[i];
    if(n==1||m==1){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=2;i<=m;i++){   
        a[i]=pre[i]-pre[i-1];   
    }
    for(int i=2;i<m;i++){
        if(a[i]>a[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    int mn=a[2];
    int ned=pre[1];
    ned-=mn*(n-m);
    if(ned<=a[2]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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