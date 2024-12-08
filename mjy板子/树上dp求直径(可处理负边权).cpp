#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

vector < vector <pair <int ,int > > > e (maxn);

int vis[maxn];
int ans;

int dfs(int u){
    vis[u] = 1;
    int d1 = 0;//向下走的最大长度
    int d2 = 0;//向下走的次大长度
    for( auto it : e[u]){
        int v = it.first;
        int w = it.second;
        if(vis[v]) continue;//防止向上查找
        int d = dfs(v) + w;//从u经过v点向下找的最大长度
        if(d >= d1) d2=d1,d1=d;
        else if(d > d2) d2 = d;
    }
    ans = max(ans , d1 + d2);
    return d1 ;//返回从u点向下走的最大长度
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u , v;
        cin>>u>>v;
        e[u].push_back(make_pair(v,1));
        e[v].push_back(make_pair(u,1));
    }
    dfs(1);
    cout <<ans<<endl;
}