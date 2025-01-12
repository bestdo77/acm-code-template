#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#pragma comment(linker, "/STACK:64000000,64000000")
const int N=1e4+10;
const int N1=1e3+10;
const int mod=1e9+7;
vector<int> e[N];
queue<int> ans;
int sz[N];
bool flag=0;
void dfs(int u){
    while(sz[u]<e[u].size()){
        sz[u]++;
        dfs(e[u][sz[u]-1]);
    }
    ans.push(u);
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    while(ans.size()){
        cout<<ans.front()<<endl;
        ans.pop();
    }
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}