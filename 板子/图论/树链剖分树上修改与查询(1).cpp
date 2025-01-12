#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5 + 10;

int n;
int fa[maxn],dep[maxn],son[maxn],sz[maxn];
//父亲，深度，重儿子，子树的结点总数
int top[maxn],id[maxn],nw[maxn],cnt;
//所在重链的顶点,剖分后的新编号，新编号在树中所对应的结点权值
int w[maxn];//点权值

vector <int > e[maxn];

void dfs1(int u,int father)//搞fa，dep，son
{
    fa[u] = father,dep[u] = dep[father] + 1,sz[u] = 1;
    for(int v : e[u]){
        if(v == father) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;//更新重儿子
    }
}

void dfs2(int u,int t)//参数为结点、所在重链顶点，搞top,id,nw
{
    top[u] = t;//记录链头
    id[u] = ++cnt,nw[cnt] = w[u];
    if(!son[u]) return;//无重儿子返回
    dfs2(son[u],t);//搜重儿子
    for(int v : e[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);//搜轻儿子，注意轻儿子的链头就是自己，不能和重儿子混淆
    }
}

#define ls k<<1
#define rs k<<1|1
/*
#define ls t[k].ls
#define rs t[k].rs
*/
const int N=maxn;
int a[N];
struct node{
    int /*ls,rs,*/sum,lz;
}t[N<<2];

void build(int k,int l,int r){
    t[k].lz = 0;
    if(l==r) {
        t[k].sum=nw[l];
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    t[k].sum=t[ls].sum+t[rs].sum;
}//建树

void modify(int k,int l,int r,int p,int q,ll val){
    t[k].sum+=val*(q-p+1);
    if(p==l&&q==r) {
        t[k].lz+=val;//一定是+=
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,val);
    else if(p>mid) modify(rs,mid+1,r,p,q,val);
    else{
        modify(ls,l,mid,p,mid,val);
        modify(rs,mid+1,r,mid+1,q,val);
    }
}

ll query(int k,int l,int r,int p,int q,ll lz){//用的时候应该lz是0，懒标记是下面的节点，自身已经维护好了
    if(p==l&&q==r) return t[k].sum+lz*(q-p+1);
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q,lz+t[k].lz);//这里有变动
    else if(p>mid) return query(rs,mid+1,r,p,q,lz+t[k].lz);
    else return query(ls,l,mid,p,mid,lz+t[k].lz)+query(rs,mid+1,r,mid+1,q,lz+t[k].lz);
}

ll query_path(int u,int v){
    ll res = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        res += query(1,1,n,id[top[u]],id[u],0);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u,v);
    res += query(1,1,n,id[v],id[u],0);
    return res;
}

void modify_path(int u,int v,int val){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        modify(1,1,n,id[top[u]],id[u],val);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u,v);
    modify(1,1,n,id[v],id[u],val);
}