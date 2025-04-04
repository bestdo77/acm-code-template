#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct edge{
    int v,w;
};
vector<int> e[N];

int dfs_order[N],p1;
void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
	dfs_order[++p1]=u;
	for(auto v:e[u]){
		dfs(v);	
	}
}


bool vis[N];
int bfs_order[N],p2;
void bfs(int u){
	queue<int> q;
	q.push(u);
    vis[u]=1;
	while(q.size()){
		int u=q.front();q.pop();
        bfs_order[++p2]=u;
		for(auto v:e[u]){
			if(vis[v]) continue;
            vis[v]=1;
			q.push(v);
		}
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end());
	}
	dfs(1);
    memset(vis,0,sizeof(vis));
    bfs(1);
	for(int i=1;i<=n;i++){
		cout<<dfs_order[i]<<" ";
	}
	cout<<endl;
    
	for(int i=1;i<=n;i++){
		cout<<bfs_order[i]<<" ";
	}
	cout<<endl;
	return 0;
} 