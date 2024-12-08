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
int f[N];
set<int,greater<int>> e[N];
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
    if(fx==fy){
        e[fx].insert(x);
        e[fx].insert(y);
        return;
    }else{
        if(e[fx].size()>e[fy].size()){
            e[fx].insert(x);
            e[fx].insert(y);
            f[fy]=fx;
            for(auto it:e[fy]){
                e[fx].insert(it);
            }
        }else{
            e[fy].insert(x);
            e[fy].insert(y);
            f[fx]=fy;
            for(auto it:e[fx]){
                e[fy].insert(it);
            }
        }
    }
}
int fk(int x, int k) {
    e[x].insert(x);
    auto it = e[x].begin();
    if (k <= e[x].size()) {
        it = next(it, k - 1);
        return *it;
    } else {
       return -1;
    }
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    init(n);
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int u,v;cin>>u>>v;
            join(u,v);
        }else{
            int x,k;cin>>x>>k;
            cout<<fk(find(x),k)<<endl;
        }
    }
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