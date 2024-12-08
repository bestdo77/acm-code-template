#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],f[N],dep[N],ans[N];
void init(int n){
    for(int i=1;i<=n;i++)  f[i]=i;
}
int find_f(int x){
    if(x==f[x]) return f[x];
    int tmp=find_f(f[x]);
    dep[x]+=dep[f[x]];
    return f[x]=tmp;
}
void join(int x,int y){
    int tmp=find_f(x);
    f[y]=find_f(x),dep[y]=dep[x]+1;
}
// vector<array<int,element>> v;
void solve(){
    int n;cin>>n;
    init(n);
    for(int i=1;i<=n-1;i++){
        int x,y,t;cin>>x>>y>>t;
        join(x,y);
        ans[f[y]]=max(ans[f[y]],dep[y]+ans[y]);
        cout<<ans[t]<<" ";
    }//并查集维护两个东西，一个是上面有多少点，一个是下面有多少点，这里的原理是，每个点都至少当过一次父亲，ans每次都会是准的
    cout<<endl;
    for(int i=1;i<=n;i++) dep[i]=0,ans[i]=0;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}