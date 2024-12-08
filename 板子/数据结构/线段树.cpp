#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
const int N=5e5+100;
int a[N];
struct node{
    int l,r,sum;
}t[N<<2];
void build(int k,int l,int r){
    if(l==r){
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    t[k].sum=t[ls].sum+t[rs].sum;
}

int query(int k,int l,int r,int p,int q){
    if(p==l&&q==r) return t[k].sum;
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q);
    else if(p>mid) return query(rs,mid+1,r,p,q);
    else return query(ls,l,mid,p,mid)+query(rs,mid+1,r,mid+1,q);
}

int modify(int k,int l,int r,int p,int v){
    if(l==r){
        t[k].sum+=v;
        return 0;
    }
    int mid=l+r>>1;
    if(p<=mid) modify(ls,r,mid,p,v);
    else modify(rs,mid+1,r,p,v);
    t[k].sum=t[ls].sum+t[rs].sum;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int opr;cin>>opr;
        if(opr==1){
            int x,v;cin>>x>>v;
            modify(1,1,n,x,v);
        }else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}