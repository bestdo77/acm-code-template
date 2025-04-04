#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=2e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
vector<int> e[N];
int a[N];
int vis[N];
int ok[N];
int cnt[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;cin>>a[i];
    }
    for(int i=1;i<=1.2e6;i++){
        int cnt=0;
        for(int j=i;j<=1.2e6;j+=i){
            e[j].emplace_back(i);
        }
        if(cnt>=k) ok[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(auto u:e[a[i]]){
            cnt[u]++;
        }
    }
    for(int i=1;i<=1.2e6;i++){
        if(cnt[i]>=k) ok[i]=1;
    }
    for(int i=1;i<=n;i++){
        // cout<<e[a[i]].size()<<endl;
        for(int j=e[a[i]].size()-1;j>=0;j--){
            if(ok[e[a[i]][j]]){
                cout<<e[a[i]][j]<<endl;
                break;
            }
        }
    }
    // cout<<1<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}