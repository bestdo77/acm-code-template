#include <bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
#define int long long
using namespace std;
const int N=1e5+7;
int n,m,mod,a[N];
struct node{
    int l=0,r=0,sum,mul=1,add=0;
}t[N*4];
void pushup(int rt){
    t[rt].sum=(t[ls].sum+t[rs].sum)%mod;
}
void build(int l,int r,int rt){
    t[rt].l=l,t[rt].r=r;
    t[rt].sum=0,t[rt].add=0,t[rt].mul=1;
    if(l==r){
        t[rt].sum=a[l]%mod;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(rt);
}
void pushdown(int rt){
    // if(p==q) return;
    // cout<<rt<<" "<<(ls)<<" "<<(rs)<<endl;
    t[ls].sum=(t[ls].sum*t[rt].mul)%mod;
    t[ls].sum=(t[ls].sum+((t[ls].r-t[ls].l+1)*t[rt].add)%mod)%mod;
    t[rs].sum=(t[rs].sum*t[rt].mul)%mod;
    t[rs].sum=(t[rs].sum+((t[rs].r-t[rs].l+1)*t[rt].add)%mod)%mod;
    //注意这里的add贡献要按儿子的区间去算
    t[ls].mul=(t[ls].mul*t[rt].mul)%mod;
    t[rs].mul=(t[rs].mul*t[rt].mul)%mod;

    t[ls].add=(t[rt].add+t[ls].add*t[rt].mul)%mod;
    t[rs].add=(t[rt].add+t[rs].add*t[rt].mul)%mod;
    t[rt].mul=1;
    t[rt].add=0;
}
void adds(int l,int r,int add,int rt){
    if(l<=t[rt].l&&t[rt].r<=r){
        t[rt].sum=(t[rt].sum+(t[rt].r-t[rt].l+1)*add)%mod;
        t[rt].add=(t[rt].add+add)%mod;
        return;
    }
    pushdown(rt);//每个点只下放一次
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) adds(l,r,add,ls);
    if(r>mid) adds(l,r,add,rs);
    pushup(rt);
}
void muls(int l,int r,int mul,int rt){
    if(l<=t[rt].l&&r>=t[rt].r){
        t[rt].sum=(t[rt].sum*mul)%mod;
        t[rt].add=(t[rt].add*mul)%mod;
        t[rt].mul=(t[rt].mul*mul)%mod;
        return;
    }
    pushdown(rt);
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid) muls(l,r,mul,ls);
    if(r>mid) muls(l,r,mul,rs);
    pushup(rt);
}
int query(int l,int r,int rt){//查询时每次都要下放
    if(l<=t[rt].l&&t[rt].r<=r){
        return t[rt].sum%mod;
    }
    int ans=0;
    pushdown(rt);
    int mid=t[rt].l+t[rt].r>>1;
    if(l<=mid) ans=(ans+query(l,r,ls))%mod;
    if(r>mid) ans=(ans+query(l,r,rs))%mod;
    return ans;   
}
signed main(){
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int opt;cin>>opt;
        switch(opt){
            case 1:{
                int l,r,k;cin>>l>>r>>k;
                k%=mod;
                muls(l,r,k,1);
                break;
            }
            case 2:{
                int l,r,k;cin>>l>>r>>k;
                k%=mod;
                adds(l,r,k,1);
                break;
            }
            case 3:{
                int l,r;cin>>l>>r;
                cout<<query(l,r,1)<<endl;
                break;
            }
        }
    }
    return 0;
}