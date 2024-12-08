#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
//复杂度n*n+m
struct edge{
    int v,w;//边的另一个点和权值。
};
int d[N],vis[N],n,m,s;//d[i]数组表示的是第i个点到目标点的最短距离
vector<edge> e[N];
void Dijkstra(int s){
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;
    for(int i=1;i<n;i++){
        int u=0;
        for(int j=1;j<=n;j++){//枚举点的
            if(!vis[j]&&d[j]<d[u]) u=j;//找距离最小的点，一开始就是从第一个点枚举
            vis[u]=1;//标记u已经出圈
            for(auto ed:e[u]){
                int v=ed.v,w=ed.w;//相邻边的终点和边权
                if(d[v]>d[u]+w){//松弛操作
                    d[v]=d[u]+w;
                }
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    Dijkstra(s);
    return 0;
}