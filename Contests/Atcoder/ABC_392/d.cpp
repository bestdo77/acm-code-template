#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int cnt1[N];
unordered_map<int,int> cnt[N];
double check(int i,int j){
    int n1=cnt1[i];
    int n2=cnt1[j];
    double ans=0;
    if(cnt[i].size()>cnt[j].size()) swap(i,j);
    for(auto &[u,v]:cnt[i]){
        ans+=(cnt[i][u])*(cnt[j][u]);
    }
    ans/=(n1*n2);
    return ans;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            double x;cin>>x;
            cnt1[i]++;
            cnt[i][x]++;
        }
    }
    double mx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mx=max(mx,check(i,j));
        }
    }
    cout<<fixed<<setprecision(12)<<mx<<endl;
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