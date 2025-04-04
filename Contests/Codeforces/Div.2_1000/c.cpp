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
unordered_map<int,int> vis[N];
bool adj(int u,int v){
    return vis[u][v]==1;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<pii> deg(n+1);
    for(int i=0;i<=n;i++){
        vis[i].clear();
        deg[i].first=0;
        deg[i].second=i;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        deg[u].first++;
        deg[v].first++;
        vis[u][v]=1;
        vis[v][u]=1;
    }
    sort(deg.begin(),deg.end());
    int mx=deg[n].first;
    int mx2=0;
    int cnt=1;
    for(int i=n-1;i>=1;i--){
        if(deg[i].first==mx) cnt++;
        if(!mx2) mx2=deg[i].first;
        else if(deg[i].first!=mx2) break;
        if(!adj(deg[i].second,deg[n].second)||cnt>=3){
            cout<<mx+mx2-1<<endl;
            return;
        }
    }
    db(mx<<" "<<mx2<<endl)
    cout<<mx+mx2-2<<endl;
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