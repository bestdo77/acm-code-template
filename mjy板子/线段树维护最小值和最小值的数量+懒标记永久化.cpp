#include <bits/stdc++.h>
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
#include<functional>


#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;

#define ls k<<1
#define rs k<<1|1
/*
#define ls t[k].ls
#define rs t[k].rs
*/
const int N=2e5+10;
int a[N];
struct node{
    int /*ls,rs,*/minn,sum,lz;
}t[N<<2];

void build(int k,int l,int r){
    t[k].lz=0;
    if(l==r) {
        t[k].sum=1;
        t[k].minn=0;
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    t[k].minn=min(t[ls].minn,t[rs].minn);
    if(t[ls].minn<t[rs].minn) t[k].sum=t[ls].sum;
    else if(t[ls].minn>t[rs].minn) t[k].sum=t[rs].sum;
    else t[k].sum=t[ls].sum+t[rs].sum;
}

void modify(int k,int l,int r,int p,int q,ll val){
    //t[k].sum+=val*(q-p+1);
    if(p==l&&q==r) {
        t[k].minn+=val;//一定是+=
        t[k].lz+=val;
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,val);
    else if(p>mid) modify(rs,mid+1,r,p,q,val);
    else{
        modify(ls,l,mid,p,mid,val);
        modify(rs,mid+1,r,mid+1,q,val);
    }
    if(t[ls].minn<t[rs].minn) {
        t[k].minn=t[ls].minn+t[k].lz;
        t[k].sum=t[ls].sum;
    }
    else if(t[ls].minn>t[rs].minn){
        t[k].minn=t[rs].minn+t[k].lz;
        t[k].sum=t[rs].sum;
    }
    else{
        t[k].minn=t[rs].minn+t[k].lz;
        t[k].sum=t[rs].sum+t[ls].sum;
    }
}

node query(int k,int l,int r,int p,int q){
    //k在查询时直接输入1（即root）
    //l,r是整个线段树的范围
    if(l==p&&r==q) return t[k];
    int mid=l+r>>1;
    if(q<=mid){
        node tt=query(ls,l,mid,p,q);
        return {t[k].lz+tt.minn, tt.sum ,t[k].lz};
    }
    if(p>mid){
        node tt = query(rs,mid+1,r,p,q);
        return {t[k].lz+tt.minn, tt.sum ,t[k].lz};
    }
    else{
        node ld=query(ls,l,mid,p,mid);
        node rd=query(rs,mid+1,r,mid+1,q);
        if(ld.minn < rd.minn){
            return {t[k].lz + ld.minn,ld.sum,t[k].lz};
        }
        else if(ld.minn > rd.minn){
            return {t[k].lz + rd.minn,rd.sum,t[k].lz};
        }
        else{
            return {ld.minn + t[k].lz,ld.sum+rd.sum,t[k].lz};
        }
    }
}