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
vector<pii> X[N];
int ans[N],pi[N];
void Atomatic_AC_machine(){
    int n,w;cin>>n>>w;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        X[x].emplace_back(make_pair(y,i));
    }
    int mx=inf;
    for(int i=1;i<=w;i++){
        sort(X[i].begin(),X[i].end());
        mx=min(mx,(int)X[i].size());
    }
    for(int i=0;i<mx;i++){
        for(int j=1;j<=w;j++){
            pi[i]=max(X[j][i].first,pi[i]);
        }
    }
    for(int i=0;i<mx;i++){
        for(int j=1;j<=w;j++){
            ans[X[j][i].second]=pi[i];
        }
    }
    // for(int i=0;i<mx;i++){
    //     db(pi[i])
    // }
    // cendl
    // for(int i=1;i<=w;i++){
    //     for(auto [u,v]:X[i]){
    //         db(v)
    //     }
    //     cendl
    // }
    // for(int i=1;i<=w;i++){
    //     for(auto [u,v]:X[i]){
    //         db(u)
    //     }
    //     cendl
    // }
    // for(int i=1;i<=n;i++){
    //     db(ans[i])
    // }
    // cendl
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int id,t;cin>>t>>id;
        if(ans[id]==0||t<=ans[id]-1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
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