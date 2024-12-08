#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
//#define endl '\n'
const int N=5e5+100;
int n;
int a[N],b[N];//del

struct node{
    int l,r,maxx,minn;
}t[N<<2];
void build(int k,int l,int r){
    if(l==r){
        t[k].maxx=a[l];
        t[k].minn=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    t[k].maxx=max(t[ls].maxx,t[rs].maxx);
    t[k].minn=min(t[ls].minn,t[rs].minn);
}

int querymax(int k,int l,int r,int p,int q){
    if(p==l&&q==r) return t[k].maxx;
    int mid=l+r>>1;
    if(q<=mid) return querymax(ls,l,mid,p,q);
    else if(p>mid) return querymax(rs,mid+1,r,p,q);
    else return max(querymax(ls,l,mid,p,mid),querymax(rs,mid+1,r,mid+1,q));
}
int querymin(int k,int l,int r,int p,int q){
    if(p==l&&q==r) return t[k].minn;
    int mid=l+r>>1;
    if(q<=mid) return querymin(ls,l,mid,p,q);
    else if(p>mid) return querymin(rs,mid+1,r,p,q);
    else return min(querymin(ls,l,mid,p,mid),querymin(rs,mid+1,r,mid+1,q));
}
void modify(int k,int l,int r,int p,int v){
    if(l==r){
        t[k].minn+=v;
        t[k].maxx+=v;
        return;
    }
    int mid=l+r>>1;
    if(p<=mid) modify(ls,l,mid,p,v);
    else modify(rs,mid+1,r,p,v);
    t[k].maxx=max(t[ls].maxx,t[rs].maxx);
    t[k].minn=min(t[ls].minn,t[rs].minn);
}