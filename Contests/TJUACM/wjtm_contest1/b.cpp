#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define inf 1000000000
using namespace std;
int n,m,first[1010]={0},qfirst[1010]={0},tot=0,S,T,k;
int h[1010];
bool vis[1010];
struct edge{int v,w;}; 
vector<edge> e[100010],qe[100010];
struct state
{
  int u,g,h;
  bool operator < (state a) const
  {
    return a.g+a.h<g+h;
  } //使用STL的优先队列，需要重载运算符
};

void insert(int a,int b,int c)
{
  e[a].push_back(edge{b,c});
  qe[b].push_back(edge{a,c});
}

void spfa() //SPFA跑反图，用dijkstra也可以
{
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++) h[i]=inf;
  queue<int> Q;
  Q.push(T);h[T]=0;
  while(!Q.empty())
  {
    int u=Q.front();
    Q.pop();
    for(int i=0;i<qe[u].size();i++)
    {
      int j=qe[u][i].v;
      if (h[u]+qe[u][i].w<h[j])
      {
        h[j]=h[u]+qe[u][i].w;
      if (!vis[j]) {Q.push(j);vis[j]=1;}
      }
    }
    vis[u]=0;
  }
}

int AStar() //A*
{
  priority_queue<state> fq;
  state now,next;
  now.u=S,now.g=0,now.h=h[S];
  fq.push(now);
  int cnt[1010]={0};
  while(!fq.empty())
  {
    now=fq.top();
    fq.pop();
    cnt[now.u]++;
    if(cnt[now.u]==k) return now.g+now.h;
    for(int i=0;i<e[now.u].size();i++)
    {
      next.u=e[now.u][i].v;
      next.g=now.g+e[now.u][i].w;
      next.h=h[e[now.u][i].v];
      fq.push(next);
    }
  }
  return -1;
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int s,t,c;
    scanf("%d%d%d",&s,&t,&c);
	  insert(s,t,c);
  }
  scanf("%d%d%d",&S,&T,&k);
  if (S==T) k++; //特殊情况，S=T
  
  spfa();
  
  printf("%d",AStar());
  
  return 0;
}