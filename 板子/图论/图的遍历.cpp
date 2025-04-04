#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> e[N];
int vis[N];
int dfs_order[N],p1;
int bfs_order[N],p2;
void dfs(int u){
	// memset(vis,0,sizeof(vis));
	dfs_order[++p1]=u;
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v]) continue;
		dfs(v);	
	}
}
void bfs(int u){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(u);
	while(q.size()){
		int u=q.front();q.pop();
		bfs_order[++p2]=u;
		vis[u]=1;
		for(auto v:e[u]){
			if(vis[v]) continue;
			q.push(v);
		}
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end());
	}
	dfs(1);
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