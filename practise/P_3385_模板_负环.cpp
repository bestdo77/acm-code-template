#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
struct edge{int v,w;};
vector<edge> e[N];
int d[N],cnt[N],vis[N];
int n,m;
queue<int> q;
bool spfa(int s){
    for(int i=1;i<=n;i++) vis[i]=cnt[i]=0;
    while(q.size()) q.pop();
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;vis[s]=1;q.push(s);
    while(q.size()){
        int u=q.front();q.pop();vis[u]=0;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return true;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return false;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        if(w>=0){
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }else e[u].push_back({v,w});
    }
    if(spfa(1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    return;
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