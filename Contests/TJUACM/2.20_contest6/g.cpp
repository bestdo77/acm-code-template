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
void pa(int *p,int n){for(int i=1;i<=n;i++){db(*(p+i))} cendl}
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
            rk[fx]+=rk[fy];
        }
    }   
};
pii op[N];
int ans;
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    ans=n*(n-1)/2;
    for(int i=1;i<=m;i++){
        cin>>op[i].first>>op[i].second;
    }
    Dsu dsu(n);
    stack<int> ans1;
    for(int i=m;i>=1;i--){
        auto [u,v]=op[i];
        ans1.push(ans);
        if(dsu.find(u)!=dsu.find(v)){
            int sz1=dsu.rk[dsu.find(u)];
            int sz2=dsu.rk[dsu.find(v)];
            dsu.join(u,v);
            ans-=sz1*sz2;
        }
    }
    while(ans1.size()){
        cout<<ans1.top()<<endl;
        ans1.pop();
    }
}   
signed main(){
    // auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
