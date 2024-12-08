#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;

int n, c, d[N];

int anc[N];
vector<int> E[N];

void dfs(int u, int fa, int flag) {//第二才记录前驱
  for (int v : E[u]) {
    if (v == fa) continue;
    if(flag) anc[v]=u;   //记录每一个前驱
    d[v] = d[u] + 1;  //这里按照边权修改
    if (d[v] > d[c]) c = v;
    dfs(v, u, flag);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    E[u].push_back(v), E[v].push_back(u);
  }
  dfs(1, 0, 0);
  d[c] = 0, dfs(c, 0, 1);
  printf("%d\n", d[c]);
// cout<<c<<endl;
//   while(anc[c]!=0){
//     cout<<anc[c]<<endl;
//     c=anc[c];
//   }
  return 0;
}