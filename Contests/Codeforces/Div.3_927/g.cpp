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

#define F 1e6
struct Dsu{
    vector<int> f,rk;
    int init(int n){
        f.assign(n+1,0);
        rk.assign(n+1,1);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    }
    Dsu(int n){
        init(n);
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
int f[N1][N1];
int sx[N],sy[N],sh[N],tx[N],ty[N],th[N];
int l[N],r[N];
struct edge{
    int u,v;
};
vector<edge> e[N];
vector<int> check[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>f[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+1<m) e[min(f[i][j],f[i][j+1])].push_back({i*m+j,i*m+j+1});
            if(i+1<n) e[min(f[i][j],f[i+1][j])].push_back({i*m+j,(i+1)*m+j});
        }
    }
    Dsu dsu(2*n*m);
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        cin>>sx[i]>>sy[i]>>sh[i]>>tx[i]>>ty[i]>>th[i];
        sx[i]--,sy[i]--,tx[i]--,ty[i]--;
    }
    for(int i=1;i<=q;i++){
        l[i]=0,r[i]=F+1;
    }
    while(true){
        bool flag=0;
        dsu.init(2*n*m);
        for(int i=1;i<=F;i++){
            check[i].clear();
        }
        for(int i=1;i<=q;i++){
            if(l[i]+1<r[i]){
                int mid=l[i]+r[i]>>1;
                check[mid].push_back(i);
                flag=1;
            }
        }
        if(!flag) break;
        for(int i=F;i>=1;i--){
            for(auto &[u,v]:e[i]){
                dsu.join(u,v);
            }
            for(auto j:check[i]){
                int pu=sx[j]*m+sy[j];
                int pv=tx[j]*m+ty[j];
                if(dsu.find(pu)==dsu.find(pv)){
                    l[j]=i;
                }else{
                    r[j]=i;
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<sh[i]+th[i]-2*min({sh[i],th[i],l[i]})<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}