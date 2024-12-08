#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=1e5+10;
#define ls k<<1
#define rs k<<1|1
struct node{
    int l,r,sum,lz;
}t[N<<2];
int a[N];
void build(int k,int l,int r){
    if(l==r){
        t[k].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    t[k].sum=t[ls].sum+t[rs].sum;
}
void modify(int k,int l,int r,int p,int q,int v){
    t[k].sum+=v*(q-p+1);//只修改懒标记之前的
    if(p==l&&q==r){
        t[k].lz+=v;
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,v);
    else if(p>mid) modify(rs,mid+1,r,p,q,v);
    else modify(ls,l,mid,p,mid,v),modify(rs,mid+1,r,mid+1,q,v);
}
int query(int k,int l,int r,int p,int q,int lz){
    if(p==l&&q==r){
        return t[k].sum+lz*(q-p+1);
    }
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q,t[k].lz+lz);
    else if(p>mid) return query(rs,mid+1,r,p,q,t[k].lz+lz);
    else return query(ls,l,mid,p,mid,t[k].lz+lz)+query(rs,mid+1,r,mid+1,q,t[k].lz+lz);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int opr;cin>>opr;
        if(opr==1){
            int l,r,v;cin>>l>>r>>v;
            modify(1,1,n,l,r,v);
        }else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r,0)<<endl;
        }
    }
    return 0;
}