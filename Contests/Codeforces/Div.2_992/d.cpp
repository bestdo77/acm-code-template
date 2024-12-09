#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
vector<int> e[N];
int ans[N],cnt;
void dfs(int u,int fa){
    cnt++;
    ans[u]=cnt;
    if((ans[u]-ans[fa])%2==1&&ans[u]-ans[fa]!=1) ans[u]++,cnt++;
    if((ans[u]-ans[fa]==2)) ans[u]+=2,cnt+=2;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        ans[i]=0;
        e[i].clear();
        cnt=0;
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}