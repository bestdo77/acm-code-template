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
int point[N];
vector<int> e[N];
multiset<int> sz[N];
void dfs(int u,int fa){
    sz[u].insert(point[u]);
    for(auto &v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
        for(auto &it:sz[v]){
            sz[u].insert(it);
        }    
        while(sz[u].size()>20){
            sz[u].erase(prev(sz[u].end()));
        }
    }
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>point[i];
        point[i]=-point[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int cnt=0;
        int v,k;cin>>v>>k;
        for(auto it:sz[v]){
            cnt++;
            if(cnt==k){
                cout<<-it<<endl;
                break;
            }
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