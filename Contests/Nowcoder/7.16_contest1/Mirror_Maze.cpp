#include<bits/stdc++.h>
#define ll long long
using namespace std;
char maze[1005][1005];
int visited[1005][1005][4];
int visitedpoint[1005][1005];
int n,m;
int dfs(int u,int v,int dir){
	if (visited[u][v][dir]) return 0;
	if (u<1||u>n||v<1||v>m) return 0;
	int now=0;
	switch(dir){
		case 0:
			if (maze[u][v]=='|'){
				now=dfs(u-1,v,dir);
			}
			else{
				visited[u][v][dir]=1;
				if (visitedpoint[u][v]==1) now=-1;
				visitedpoint[u][v]=1;
				switch(maze[u][v]){
					case '-':now+=1+dfs(u+1,v,1);break;
					case '/':now+=1+dfs(u,v+1,3);break;
					case '\\':now+=1+dfs(u,v-1,2);break; 
				}
				visitedpoint[u][v]=0;
				visited[u][v][dir]=0;
			}
			break;
		case 1:
			if (maze[u][v]=='|'){
				now=dfs(u+1,v,dir);
			}
			else{
				visited[u][v][dir]=1;
				if (visitedpoint[u][v]==1) now=-1;
				visitedpoint[u][v]=1;
				switch(maze[u][v]){
					case '-':now+=1+dfs(u-1,v,0);break;
					case '/':now+=1+dfs(u,v-1,2);break;
					case '\\':now+=1+dfs(u,v+1,3);break; 
				}
				visitedpoint[u][v]=0;
				visited[u][v][dir]=0;
			}
			break;
		case 2:
			if (maze[u][v]=='-'){
				now=dfs(u,v-1,dir);
			}
			else{
				visited[u][v][dir]=1;
				if (visitedpoint[u][v]==1) now=-1;
				visitedpoint[u][v]=1;
				switch(maze[u][v]){
					case '|':now+=1+dfs(u,v+1,3);break;
					case '/':now+=1+dfs(u+1,v,1);break;
					case '\\':now+=1+dfs(u-1,v,0);break; 
				}
				visitedpoint[u][v]=0;
				visited[u][v][dir]=0;
			}
			break;
		case 3:
			if (maze[u][v]=='-'){
				now=dfs(u,v+1,dir);
			}
			else{
				visited[u][v][dir]=1;
				if (visitedpoint[u][v]==1) now=-1;
				visitedpoint[u][v]=1;
				switch(maze[u][v]){
					case '|':now+=1+dfs(u,v-1,2);break;
					case '/':now+=1+dfs(u-1,v,0);break;
					case '\\':now+=1+dfs(u+1,v,1);break; 
				}
				visitedpoint[u][v]=0;
				visited[u][v][dir]=0;
			}
			break; 
	}
	return now;
}
void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>maze[i][j]; 
		}
	}
	int q;
	cin>>q;
	int u,v,ans;
	string s; 
	for (int i=1;i<=q;i++){
		cin>>u>>v>>s;
		if (s=="above") ans=dfs(u-1,v,0);
		else if (s=="below") ans=dfs(u+1,v,1);
		else if (s=="left") ans=dfs(u,v-1,2);
		else if (s=="right") ans=dfs(u,v+1,3);
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
} 