#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<i64, i64>
#define endl '\n'
const i64 N=1e6+10;
const i64 N1=1e3+10;
const i64 mod=1e9+7;
const i64 element=3;
vector<i64> G[N];
int f[N];
void init(int n){
    for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x){
    if(x!=f[x]) return f[x]=find(f[x]);
    return f[x];
}
bool join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        f[fy]=fx;
        return 1;
    }else return 0;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n+1;i++) f[i]=i;
    int ans=1;
    for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        ans&=join(l,r+1);
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    i64 t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}