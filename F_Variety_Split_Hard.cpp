#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif


const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

#define ls k<<1
#define rs k<<1|1
/*
#define ls t[k].ls
#define rs t[k].rs
*/

int a[N];
struct node{
    int /*ls,rs,*/maxx,sum,lz;
}t[N<<2];

void build(int k,int l,int r){
    t[k].lz=0;
    if(l==r) {
        t[k].sum=1;
        t[k].maxx=0;
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    t[k].maxx=max(t[ls].maxx,t[rs].maxx);
    if(t[ls].maxx>t[rs].maxx) t[k].sum=t[ls].sum;
    else if(t[ls].maxx<t[rs].maxx) t[k].sum=t[rs].sum;
    else t[k].sum=t[ls].sum+t[rs].sum;
}

void modify(int k,int l,int r,int p,int q,i64 val){
    //t[k].sum+=val*(q-p+1);
    if(p==l&&q==r) {
        t[k].maxx+=val;//一定是+=
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
    if(t[ls].maxx>t[rs].maxx) {
        t[k].maxx=t[ls].maxx+t[k].lz;
        t[k].sum=t[ls].sum;
    }
    else if(t[ls].maxx<t[rs].maxx){
        t[k].maxx=t[rs].maxx+t[k].lz;
        t[k].sum=t[rs].sum;
    }
    else{
        t[k].maxx=t[rs].maxx+t[k].lz;
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
        return {t[k].lz+tt.maxx, tt.sum ,t[k].lz};
    }
    if(p>mid){
        node tt = query(rs,mid+1,r,p,q);
        return {t[k].lz+tt.maxx, tt.sum ,t[k].lz};
    }
    else{
        node ld=query(ls,l,mid,p,mid);
        node rd=query(rs,mid+1,r,mid+1,q);
        if(ld.maxx > rd.maxx){
            return {t[k].lz + ld.maxx,ld.sum,t[k].lz};
        }
        else if(ld.maxx < rd.maxx){
            return {t[k].lz + rd.maxx,rd.sum,t[k].lz};
        }
        else{
            return {ld.maxx + t[k].lz,ld.sum+rd.sum,t[k].lz};
        }
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    vector<int> suf(n+2,0);
    vector<int> vis(n+1,0),lst(n+1,0);
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        if(!vis[a[i]]){
            suf[i]=suf[i+1]+1;
            vis[a[i]]=1;
        }
    }
    i64 ans=suf[1];
    for(int i=1;i<=n-1;i++){
        i64 tmp=suf[i+1];
        if(!lst[a[i]]){
            modify(1,1,n,1,n,1);
        }else{
            modify(1,1,n,lst[a[i]]+1,i,1);
        }
        lst[a[i]]=i;
        node t=query(1,1,n,1,i);
        tmp+=t.maxx;
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}