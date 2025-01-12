//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>

#define int long long
#define pii pair<int,int>
using namespace std;
typedef long long ll;

const int maxn=1e3+10;

int dis[110];
int vis[110];


void solve (){
    int n,k;
    cin>>n>>k;
    vector<vector<pii> > e(110);
    for(int i=1;i<=k;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(make_pair(v,w));
        e[v].push_back(make_pair(u,w));
    }
    int ans=0;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;//记得想一下排序规则
    q.push(make_pair(0,1));
    while(!q.empty()){
        int d=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ans+=d;
        for(auto [v,w]:e[u]){
            if(w<dis[v]){
                dis[v]=w;
                q.push(make_pair(w,v));
            }
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}