#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
int mod=1e9+7;
#define ls k<<1
#define rs k<<1|1
int n;
struct node{
    int mx;
}t[N<<2];
void modify(int k,int l,int r,int p,int v){
    if(p==l&&p==r) {
        t[k].mx+=v;
        return;
    }
    int mid=l+r>>1;
    if(p<=mid) modify(ls,l,mid,p,v);
    else modify(rs,mid+1,r,p,v);
    t[k].mx=max(t[ls].mx,t[rs].mx);
}
int query(int k,int l,int r,int p,int q){
    if(p==l&&q==r) return t[k].mx;
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q);
    else if(p>mid) return query(rs,mid+1,r,p,q);
    else return max(query(ls,l,mid,p,mid),query(rs,mid+1,r,mid+1,q));
}
void Atomatic_AC_machine(){    
    cin>>n>>mod;
    int len=0;
    int last=0;
    for(int i=1;i<=n;i++){
        char op;int v;
        cin>>op>>v;
        if(op=='A'){
            modify(1,1,n,++len,v+last%mod);
        }else{
            last=query(1,1,n,len-v+1,len);
            cout<<query(1,1,n,len-v+1,len)<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}