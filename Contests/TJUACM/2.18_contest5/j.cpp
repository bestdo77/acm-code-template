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
            if (rk[fx]<rk[fy]) {
                swap(fx,fy);
            }
            f[fy]=fx;
            rk[fx]+=rk[fy];
        }
    }   
};
int D[N];
int deg[N];
vector<int> ok[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    int sum=0;
    Dsu dsu(n);
    for(int i=1;i<=n;i++){
        cin>>D[i];
        sum+=D[i];
        if(D[i]<=0){
            db(1)
            cendl
            cout<<-1<<endl;
            return;
        }
    } 
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        dsu.join(u,v);
        D[u]--;
        D[v]--;
    }
    vector<vector<int>> c2;
    vector<int> c1;
    vector<int> vis(n+1,0);
    vector<pii> ans;
    if(sum!=2*(n-1)){
        db(2)
        cendl
        cout<<-1<<endl;
        return;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=D[i];j++) ok[dsu.find(i)].push_back(i);
        }
        vector<vector<int>> c2;
        vector<int> c1;
        print(c1);
        for(int i=1;i<=n;i++){
            if(ok[i].size()>=2) c2.push_back(ok[i]);
            else if(ok[i].size()==1) c1.push_back(ok[i][0]);
        }
        for(auto v:c2){
            for(int i=0;i<v.size()-1;i++){
                if(c1.empty()){
                    db(3)
                    cendl
                    cout<<-1<<endl;
                    return;
                }
                dsu.join(v[i],c1.back());
                ans.push_back(make_pair(v[i],c1.back()));
                c1.pop_back();
            }
            c1.push_back(v.back());
        }
        if(c1.size()!=2) {
            cout<<-1<<endl;
            return;
        }else{
            dsu.join(c1[0],c1[1]);
            ans.push_back({c1[0],c1[1]});
        }
        for(int i=1;i<=n;i++){
            if(dsu.find(1)!=dsu.find(i)){
                cout<<"-1"<<endl;
                return;
            }
        }
        for(auto &[u,v]:ans){
            cout<<u<<" "<<v<<endl;
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