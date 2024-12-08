#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int ans;
struct Dsu{
    int f[N],A[N],B[N];
    void init(int n){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    }
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }
    void join(int x,int y,int w){
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy){
            f[fy]=fx;
            A[fx]+=A[fy];
            B[fx]+=B[fy];
            int x=min(A[fx],B[fx]);
            A[fx]-=x;
            B[fx]-=x;
            ans+=x*w;
        }
    }   
}dsu;
struct ed{
    int u,v,w;
    bool operator<(const ed &other) const{
        return w<other.w;
    }
}a[N];
void Atomatic_AC_machine(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=k;i++){
        int x;cin>>x;
        dsu.A[x]++;
    }
    for(int i=1;i<=k;i++){
        int x;cin>>x;
        dsu.B[x]++;
    }
    dsu.init(n);
    for(int i=1;i<=m;i++){
        // cout<<dsu.find(a[i].u)<<" "<<dsu.find(a[i].v)<<endl;
        dsu.join(a[i].u,a[i].v,a[i].w);
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}