#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct edge{
	int u,v;
};
bool vis1[110000],vis2[110000];
vector<int> e[110000];
vector<edge> s;
bool cmp(edge x,edge y){
	if(x.u==y.u) return x.v<y.v;
	else return x.u<y.u;
}
void dfs(int x){
	vis1[x]=1;
	cout<<x<<" ";
	for(int i=0;i<e[x].size();i++){
		int pos=s[e[x][i]].v;
		if(vis1[pos]!=1){
			dfs(pos);
		}
	}
}
void bfs(int x){//x表示顶点. 
	queue<int> q;
	q.push(x);
	cout<<x<<" ";
	vis2[x]=1;
	while(!q.empty()){
		int pos=q.front();//顶点位置 
		for(int i=0;i<e[pos].size();i++){
			if(vis2[s[e[pos][i]].v]!=1){
				cout<<s[e[pos][i]].v<<" ";
				q.push(s[e[pos][i]].v);
				vis2[s[e[pos][i]].v]=1;
			}
		}
		q.pop();
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int uu,vv;
		cin>>uu>>vv;
		s.push_back((edge){uu,vv});
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<m;i++){
		e[s[i].u].push_back(i);
	}
	dfs(1);
	cout<<endl;
	bfs(1);
	return 0;
} 