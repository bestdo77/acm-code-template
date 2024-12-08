#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> g[maxn];
bool vis[maxn];
int n,d,ans;

void dfs(int x,int dis)
{
	vis[x]=1;
	if(dis<=d)
	{
		ans++; 
        if(dis==d) return;
	}
	for(int i=0;i<g[x].size();i++)
	{
		if(!vis[g[x][i]])//相通的没去过就去		
			dfs(g[x][i],dis+1);  

	}
}
int main()
{
	cin>>n>>d;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans-1;
}