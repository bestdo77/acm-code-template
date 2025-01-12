#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
const int N=2e5+10;
int s[N];
int idx=1;
int sz[N];
int pos[N],id=0;
int ans[N],pre[N];
vector<int> e[N];
int lowbit(int x){
    return x&(-x);
}
int add(int x,int v){
    while(x<=idx+1) s[x]+=v,x+=lowbit(x);
}
int query(int x){
    int re=0;
    while(x){
        re+=s[x];
        x-=lowbit(x);
    }
    return re;
}
void dfs(int u){
    pos[u]=++id;
    for(auto it:e[u]){
        dfs(it);
        sz[u]+=sz[it];
    }
}
signed main(){
    int n;cin>>n;
    vector<pii> op{};
    for(int i=1;i<=n;i++){
        int opr,u;cin>>opr>>u;
        if(opr==1){
            e[u].push_back(++idx);
            op.push_back({opr,idx});
        }else op.push_back({opr,u});  
    }
    for(int i=1;i<=idx;i++){
        sz[i]=1;
    }
    dfs(1);
    for(auto opr:op){
        int xx=opr.first,u=opr.second;
        if(xx==1) pre[u]=query(pos[u]);
        else{
            add(pos[u],1);
            add(pos[u]+sz[u],-1);
        }
    }
    for(int i=1;i<=idx;i++){
        ans[i]=query(pos[i])-pre[i];
    }
    for(int i=1;i<=idx;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}