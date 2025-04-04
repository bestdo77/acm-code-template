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
#include <bits/stdc++.h>
using namespace std;
#define tii tuple<int,int,int>
set<pii> hav[N];
struct Dsu{
    vector<int> f,rk;
    Dsu(int n){
        f.assign(n+1,0);
        rk.assign(n+1,1);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    };
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }
    void join(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if (fx!=fy) {
            f[fy]=fx;
        }
    }   
};
int has[N];
pii edge[N];
int vis[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    Dsu dsu(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[i]={u,v};
        if(dsu.find(u)!=dsu.find(v)) dsu.join(u,v);
        else vis[i]=1;
    }
    vector<int> vis1(n+1,0);
    vis1[dsu.find(1)]=1;
    set<int> q;
    for(int i=1;i<=n;i++){
        if(!vis1[dsu.find(i)]){
             q.insert(i);
             vis1[dsu.find(i)]=1;
        }
    }
    vector<tii> ans;
    for(int i=1;i<=m;i++){
        if(q.size()==0) break;
        auto [u,v]=edge[i];
        if(vis[i]){
            if(dsu.find(u)==dsu.find(1)){
                while(dsu.find(*q.begin())==dsu.find(1)){
                    q.erase(q.begin());
                }
                if(q.size()==0) break;
                ans.emplace_back(tii{i,u,*q.begin()});
                dsu.join(*q.begin(),1);
                q.erase(q.begin());
            }else{
                ans.emplace_back(tii{i,u,1});
                dsu.join(u,1);
                q.erase(u);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto [u,v,w]:ans){
        cout<<u<<" "<<v<<" "<<w<<endl;
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