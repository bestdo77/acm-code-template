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
    for(int i=0;i<=n;i++) vis[i]=cnt[i]=0;
    while(q.size()) q.pop();
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;vis[s]=1;q.push(s);
    while(q.size()){
        int u=q.front();q.pop();vis[u]=0;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n+1) return true;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return false;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w,opr;cin>>opr>>u>>v;
        if(opr==1){
            cin>>w;
            e[u].push_back({v,-w});//x-y>=c
        }else if(opr==2){
            cin>>w;
            e[v].push_back({u,w});//x-y<=c
        }else{
            e[v].push_back({u,0});
            e[u].push_back({v,0});//x==y
        }
    }
    for(int i=1;i<=n;i++){
        e[0].push_back({i,0});
    }
    if(!spfa(0)){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
    return 0;
}