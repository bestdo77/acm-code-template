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
void print(vector<int> a);
vector<int> generate_data(int n, int range);
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
void Atomatic_AC_machine(){
    int n,m1,m2;cin>>n>>m1>>m2;
    Dsu F(n),G(n);
    vector<pii> e1(m1+1),e2(m2+1);
    for(int i=1;i<=m1;i++){
        cin>>e1[i].first>>e1[i].second;
    }
    for(int i=1;i<=m2;i++){
        cin>>e2[i].first>>e2[i].second;
    }
    for(int i=1;i<=m2;i++){
        G.join(e2[i].first,e2[i].second);
    }
    int ans=0;
    for(int i=1;i<=m1;i++){
        int u=e1[i].first,v=e1[i].second;
        if(G.find(u)!=G.find(v)){
            ans++;
        }else{
            F.join(u,v);
        }
    }
    for(int i=1;i<=n;i++){
        if(F.find(G.find(i))!=F.find(i)){
            F.join(F.find(i),G.find(i));
            ans++;
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        //cout << "Case #" << i << ": ";
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
vector<int> generate_data(int n, int range) {
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = 1 + RNG() % range; // 生成 1 到 range 之间的随机数
    }
    return data;
}
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}