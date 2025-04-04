#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N1=1e3+10;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
//#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表存图
int d[N],n,m,s;
bool vis[N];
int ok[N];
int no[N];
int ans[N];
int a[N1][N1];
priority_queue <pii,vector<pii>,greater<pii>> q;
void dijkstra(int s){
    for(int i=0;i<=n;i++) d[i]=inf;
    for(int i=0;i<=n;i++) vis[i]=0;
    d[s]=0;q.push({0,s});
    while(q.size()){//按最远的排序
        auto t=q.top();q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;//标记u已经入队
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v;
        e[u].push_back({v,1});
        e[v].push_back({u,1});
    }
    int k;cin>>k;
    if(k==0){
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++){
            cout<<1;
        }
        cout<<endl;
        return 0;
    }
    vector<int> ss;
    for(int i=1;i<=k;i++){
        int s,ds;cin>>s>>ds;
        ss.emplace_back(s);
        dijkstra(s);
        for(int j=1;j<=n;j++){
            if(d[j]<ds) no[j]=1;
            if(d[j]==ds) a[s][j]=1;
        }
    }
    for(int j=1;j<=n;j++){
        if(no[j]){
            for(int i=1;i<=n;i++){
                a[i][j]=0;
            }
        }
    }
    bool flag=1;
    for(int i=0;i<k;i++){
        int p=ss[i];
        // cout<<p<<endl;
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[p][j]){
                ok[j]=1;
                cnt++;
            }
        }
        if(cnt==0){
            flag=0;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++){
            if(ok[i]) cout<<1;
            else cout<<0;
        }
    }else{
        cout<<"No"<<endl;
    }
    
    return 0;
}