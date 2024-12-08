#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=4e6+10;
const int N1=1e3+10;
// const int mod=1e9+7;
const int element=3;
#define ls k<<1
#define rs k<<1|1
int n,m,rt,mod;
int node[N],cnt;
int fa[N],dep[N],sz[N],son[N];
int top[N],id[N],nw[N];
vector<int> e[N];
struct node{
    int sum,lz;
}t[N<<2];
void build(int k,int l,int r){
    if(l==r){
        t[k].sum=nw[l]%mod;
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    t[k].sum=(t[ls].sum+t[rs].sum)%mod;
}
void modify(int k,int l,int r,int p,int q,int v){
    t[k].sum=(t[k].sum+v*(q-p+1)%mod)%mod;
    if(p==l&&q==r){
        t[k].lz=(t[k].lz+v)%mod;
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,v);
    else if(p>mid) modify(rs,mid+1,r,p,q,v);
    else modify(ls,l,mid,p,mid,v),modify(rs,mid+1,r,mid+1,q,v);
}
int query(int k,int l,int r,int p,int q,int lz){
    if(p==l&&q==r){
        return (t[k].sum+lz*(q-p+1)%mod)%mod;
    }
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q,(t[k].lz+lz)%mod);
    else if(p>=mid+1) return query(rs,mid+1,r,p,q,(t[k].lz+lz)%mod);
    else return (query(ls,l,mid,p,mid,(t[k].lz+lz)%mod)+query(rs,mid+1,r,mid+1,q,(t[k].lz+lz)%mod))%mod;
}
int querypath(int u,int v){
    int res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=(res+query(rt,1,n,id[top[u]],id[u],0))%mod;
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res=(res+query(rt,1,n,id[v],id[u],0))%mod;
    return res;
}
void modifypath(int u,int v,int val){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        modify(rt,1,n,id[top[u]],id[u],val);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    modify(rt,1,n,id[v],id[u],val);
}
void dfs(int u,int f){
    // if(e[u].size()==1&&e[u][0]==f){sz[u]=1;}
    sz[u]=1;
    for(auto v:e[u]){
        if(v==f) continue;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
}
void dfs1(int u,int t){
    top[u]=t,id[u]=++cnt,nw[cnt]=node[u];
    if(!son[u]) return;
    dfs1(son[u],t);
    for(auto v:e[u]){
        if(v==son[u]||v==fa[u]) continue; 
        dfs1(v,v);
    }
}
void Atomatic_AC_machine(){
    cin>>n>>m>>rt>>mod;
    for(int i=1;i<=n;i++){
        cin>>node[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(rt,0);
    dfs1(rt,rt);
    build(rt,1,n);
    // for(int i=1;i<=n;i++){
    //     cout<<nw[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<son[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<id[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<sz[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=m;i++){
        int op;cin>>op;
        if(op==1){
            int u,v,val;cin>>u>>v>>val;
            modifypath(u,v,val);
        }else if(op==2){
            int u,v;cin>>u>>v;
            cout<<querypath(u,v)<<endl;
        }else if(op==3){
            int u,val;cin>>u>>val;
            modify(rt,1,n,id[u],id[u]+sz[u]-1,val);
        }else{
            int u;cin>>u;
            cout<<query(rt,1,n,id[u],id[u]+sz[u]-1,0)<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}