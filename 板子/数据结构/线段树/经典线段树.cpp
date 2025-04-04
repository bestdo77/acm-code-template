#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int n,m;
int a[N];
#define ls k<<1
#define rs k<<1|1
struct SegTree{
    int l,r,sum;
    int lz;
}t[N<<2];
void pushup(int k){
    t[k].sum=t[ls].sum+t[rs].sum;
}
void build(int k,int l,int r){
    t[k].l=l,t[k].r=r;
    t[k].sum=t[k].lz=0;
    if(l==r){
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(k);
}
void pushdown(int k){
    if(t[k].lz){
        t[ls].sum+=(t[ls].r-t[ls].l+1)*t[k].lz;
        t[rs].sum+=(t[rs].r-t[rs].l+1)*t[k].lz;

        t[ls].lz+=t[k].lz;
        t[rs].lz+=t[k].lz;
        t[k].lz=0;
    }
}
void modify(int k,int l,int r,int p,int q,int v){
    if(p==l&&q==r){
        t[k].sum+=v*(r-l+1);
        t[k].lz+=v;
        return;
    }
    pushdown(k);
    int mid=(l+r)/2;
    if(q<=mid) modify(ls,l,mid,p,q,v);
    else if(p>mid) modify(rs,mid+1,r,p,q,v);
    else modify(ls,l,mid,p,mid,v),modify(rs,mid+1,r,mid+1,q,v);
    pushup(k);
}
int query(int k,int l,int r,int p,int q){
    if(p==l&&q==r){
        return t[k].sum;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    int ans=0;
    if(q<=mid){
        return query(ls,l,mid,p,q);
    }else if(p>mid){
        return query(rs,mid+1,r,p,q);
    }else{
        return query(ls,l,mid,p,mid)+query(rs,mid+1,r,mid+1,q);
    }
}
signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,k;cin>>l>>r>>k;
            modify(1,1,n,l,r,k);
        }else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}