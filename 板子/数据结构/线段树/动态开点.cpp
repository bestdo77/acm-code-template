#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000],cnt=1;//++cnt，因为有个父节点所以从1开始。
const int N=1e5+10;
#define ls t[k].l
#define rs t[k].r
struct node{
    int l,r,sum,lz;
}t[N<<5];
void modify(int &k,int l,int r,int p,int q,int val){
    if(!k) k=++cnt;t[k].sum+=val*(q-p+1);
    if(p==l&&q==r){
        t[k].lz+=val;
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,val);
    else if(p>mid) modify(rs,mid+1,r,p,q,val);
    else modify(ls,l,mid,p,mid,val),modify(rs,mid+1,r,mid+1,q,val);
}
int query(int k,int l,int r,int p,int q,int lz){
    if(!k) return 0;
    if(p==l&&q==r){
        return t[k].sum+lz*(r-l+1);
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
    int n,q,sum;cin>>n>>q;
    for(int i=1;i<=n;i++){
        int k=1;
        cin>>a[i];
        modify(k,1,n,i,i,a[i]);
    }
    for(int i=1;i<=q;i++){
        int opr;cin>>opr;
        if(opr==1){
            int l,r,v;cin>>l>>r>>v;
            int k=1;//每次都是父节点开始。
            modify(k,1,n,l,r,v);
        }else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r,0)<<endl;
        }
    }
    return 0;
}