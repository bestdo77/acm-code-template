#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());




const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
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
    int n,m;cin>>n>>m;
    Dsu dsu(n);
    int cnt=0;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        if(dsu.find(u)==dsu.find(v)){
            cnt++;
        }else{
            dsu.join(u,v);
        }
    }
    cout<<cnt<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}