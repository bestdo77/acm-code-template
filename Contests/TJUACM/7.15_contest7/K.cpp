#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
const int N=4e6+10;
int a[N];
int pick1[N],pick2[N],p1,p2;
int ans1[N],ans2[N];
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

int query(int k,int l,int r,int rk){
    if(l==r) return l;
    int mid=l+r>>1,x=t[ls].sum;
    if(x>=rk) return query(ls,l,mid,rk);
    else return query(rs,mid+1,r,rk-x);
}
void modify(int k,int l,int r,int p,int v){
    if(l==r){
        t[k].sum+=v;
        return;
    }
    int mid=l+r>>1;
    if(p<=mid) modify(ls,l,mid,p,v);
    else modify(rs,mid+1,r,p,v);
    t[k].sum=t[ls].sum+t[rs].sum;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) a[i]=1;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        if(i<=n/2) cin>>pick1[i];
        else cin>>pick2[i-n/2];
    }
    for(int i=1;i<=n;i++){
        if(i%2){
            p1++;
            int tmp=query(1,1,n,pick1[p1]);
            ans1[p1]=tmp;
            modify(1,1,n,tmp,-1);
        }else{
            p2++;
            int tmp=query(1,1,n,pick2[p2]);
            ans2[p2]=tmp;
            modify(1,1,n,tmp,-1);
        }
    }
    for(int i=1;i<=n/2;i++){
        cout<<ans1[i]<<" ";
    }cout<<"\n";
    for(int i=1;i<=n/2;i++){
        cout<<ans2[i]<<" ";
    }cout<<"\n";
    return 0;
}