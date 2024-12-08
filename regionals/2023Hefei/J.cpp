#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;

#define pii pair<int,int> 

pii dis[maxn];
pii ldis[maxn];
vector <pii> e[maxn];
struct nd{
    int x;
    pii dis;
    bool flag;
    bool operator < (const nd b ) const{
        auto u = dis,v= b.dis;
        if(u.first + u.second > v.first + v.second){
            return true;
        }
        else return false;
    }
};
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(make_pair(v,w));
        e[v].push_back(make_pair(u,w));
    }
    priority_queue<nd> q;
    for(int i = 2;i<=n;i++){
        dis[i].first = 0x3f3f3f3f;
        dis[i].second = 0x3f3f3f3f;
        ldis[i].first = 0x3f3f3f3f;
        ldis[i].second = 0x3f3f3f3f;
    }
    q.push({1,make_pair(0,0),1});
    q.push({1,make_pair(0,0),0});
    while(!q.empty()){
        int x = q.top().x;
        int llong = q.top().dis.first;
        int clong = q.top().dis.second;
        int flag = q.top().flag;
        q.pop();
        if(flag){
            if(llong + clong > dis[x].first + dis[x].second) continue;
            for(auto it : e[x]){
            int v = it.first;
            int w = it.second;
            int vllong = dis[v].first,vclong = dis[v].second;

            int l = llong,c = clong, z = w;
                if(l < c) swap(l,c);
                if(c < z) swap(c,z);
                if(l < c) swap(l,c);
            //用最短路松弛最短路
            if(llong + clong + w - min({llong,clong,w}) < vllong + vclong){
                dis[v].first = l;
                dis[v].second = c;
                q.push({v,dis[v],1});
            }
            //用最短路松弛最长路最短路
            if(l<ldis[v].first||(l==ldis[v].first && c < ldis[v].second)){
                ldis[v].first = l;
                ldis[v].second = c;
                q.push({v,ldis[v],0});
            }
            }
        }
        else{
            if(llong > ldis[x].first ||(llong == dis[x].first && clong > ldis[x].second)) continue;
            for(auto it : e[x]){
            int v = it.first;
            int w = it.second;
            int vllong = dis[v].first,vclong = dis[v].second;

            int l = llong,c = clong, z = w;
                if(l < c) swap(l,c);
                if(c < z) swap(c,z);
                if(l < c) swap(l,c);
            //用最长路最短路 松弛最短路
            if(llong + clong + w - min({llong,clong,w}) < vllong + vclong){
                dis[v].first = l;
                dis[v].second = c;
                q.push({v,dis[v],1});
            }
            //用最长路最短路 松弛最长路最短路
            if(l<ldis[v].first||(l==ldis[v].first && c < ldis[v].second)){
                ldis[v].first = l;
                ldis[v].second = c;
                q.push({v,ldis[v],0});
            }
            }
        }
        
        
    }
    cout<<dis[n].first + dis[n].second;
}