#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> e[N];
int match[N];//右节点跟哪个左节点匹配了
int vis[N],vist[N];//右部图匹配了
int n,m,ee;
bool dfs(int u,int tag){
    if(vist[u]==tag) return false;
    vist[u]=tag;
    for(auto v:e[u]){
        if(match[v]==0||dfs(match[v],tag)){
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m>>ee;
    for(int i=1;i<=ee;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dfs(i,i);
    }
    cout<<ans<<endl;
}