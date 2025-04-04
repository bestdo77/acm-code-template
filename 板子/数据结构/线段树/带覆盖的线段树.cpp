#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define endl '\n'
#define int long long
int n,m;
int a[N];
#define inf 0x3f3f3f3ff3f3f3f
#define ls k<<1
#define rs k<<1|1
struct SegTree{
    int l,r,mx;
    int lz;
    int over;
}t[N<<2];
void pushup(int k){
    t[k].mx=max(t[ls].mx,t[rs].mx);
}
void build(int k,int l,int r){
    t[k].l=l,t[k].r=r;
    t[k].mx=t[k].lz=0;
    t[k].over=-inf;
    if(l==r){
        t[k].mx=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(k);
}
void pushdownc(int k){
    if(t[k].over!=-inf){
        t[ls].lz=t[rs].lz=0;
        
        t[ls].mx=t[k].over;
        t[rs].mx=t[k].over;

        t[ls].over=t[k].over;
        t[rs].over=t[k].over;
        t[k].over=-inf;
    }
}
void pushdown(int k){
    if(t[k].lz){
        pushdownc(k);
        t[ls].mx+=t[k].lz;
        t[rs].mx+=t[k].lz;

        t[ls].lz+=t[k].lz;
        t[rs].lz+=t[k].lz;
        t[k].lz=0;
    }
}
void modify(int k,int l,int r,int p,int q,int v){
    if(p==l&&q==r){
        t[k].mx+=v;
        t[k].lz+=v;
        return;
    }
    pushdownc(k);
    pushdown(k);
    int mid=(l+r)>>1;
    if(q<=mid) modify(ls,l,mid,p,q,v);
    else if(p>mid) modify(rs,mid+1,r,p,q,v);
    else modify(ls,l,mid,p,mid,v),modify(rs,mid+1,r,mid+1,q,v);
    pushup(k);
}
void modifyc(int k,int l,int r,int p,int q,int v){
    // db(t[k].mx<<" "<<l<<" "<<r<<" "<<p<<" "<<q<<" "<<v)
    // cendl
    if(p==l&&q==r){
        t[k].mx=v;
        t[k].over=v;
        t[k].lz=0;
        return;
    }
    pushdownc(k);
    pushdown(k);
    int mid=(l+r)>>1;
    if(q<=mid) modifyc(ls,l,mid,p,q,v);
    else if(p>mid) modifyc(rs,mid+1,r,p,q,v);
    else modifyc(ls,l,mid,p,mid,v),modifyc(rs,mid+1,r,mid+1,q,v);
    pushup(k);
}

int query(int k,int l,int r,int p,int q){
    // db(t[k].mx<<" "<<l<<" "<<r<<" "<<p<<" "<<q)
    // cendl
    if(p==l&&q==r){
        return t[k].mx;
    }
    pushdownc(k);
    pushdown(k);
    int mid=(l+r)>>1;
    int ans=0;
    if(q<=mid){
        return query(ls,l,mid,p,q);
    }else if(p>mid){
        return query(rs,mid+1,r,p,q);
    }else{
        return max(query(ls,l,mid,p,mid),query(rs,mid+1,r,mid+1,q));
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,k;cin>>l>>r>>k;
            modifyc(1,1,n,l,r,k);
        }else if(op==2){
            int l,r,k;cin>>l>>r>>k;
            modify(1,1,n,l,r,k);
        }else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}