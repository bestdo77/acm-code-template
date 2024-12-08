#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int f[N<<1];
void init(int n){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
}
int find(int x){
    if(x!=f[x]) return f[x]=find(f[x]);
    return f[x];
}
void join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy) f[fy]=fx;
}
struct edg{
    int u,v,w;
}a[N];
bool cmp(edg a,edg b){
    return a.w>b.w;
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    init(2*n);
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        int u=a[i].u,v=a[i].v;
        if(find(u)==find(v)){
            cout<<a[i].w<<endl;
            return;
        }else{
            join(u,v+n);
            join(v,u+n);
        }
    }
    cout<<0<<endl;
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