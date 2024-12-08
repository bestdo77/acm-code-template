#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;

int tre[N];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int d){
    while(x<N){
        tre[x] += d;
        x += lowbit(x);
    }
    return;
}
int getsum(int x){
    int res = 0;
    while(x>0){
        res += tre[x];
        x-=lowbit(x);
    }
    return res;
}
vector<int> e[N];
int vis[N],deg[N];
int huan[N];
int cnt;
int dfs(int u,int father){
    vis[u] = 1;
    for(int v:e[u]){
        if(v == father) continue;
        if(vis[v]) {
            huan[++cnt] = u;
            return v;}
        else {
            int flag = dfs(v,u);
            if(flag){
                huan[++cnt] = u;
                if(flag == u){
                    return 0;
                }
                else{
                    return flag;
                }
            }
        }
    }
    return 0;
}

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1;i<=n;i++){
        add(deg[i],1);
    }
    dfs(1,0);
    // for(int i = 1;i<=cnt;i++){
    //     cout<<huan[i]<<" ";
    // }
    huan[cnt + 1] = huan[1];
    int ans = 0;
    for(int i = 1;i<=cnt;i++){
        int u = huan[i],v = huan[i+1];
        add(deg[u],-1),add(deg[v],-1);
        add(deg[u]-1,1),add(deg[v]-1,1);
        if(getsum(3)>0&&(getsum(N-1) - getsum(4) == 0)) ans+= getsum(3);

        add(deg[u]-1,-1),add(deg[v]-1,-1);
        add(deg[u],1),add(deg[v],1);
    }
    cout<<ans<<endl;
}