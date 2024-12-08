#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
#define endl '\n'
const int N=10;
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
bool high(int l,int r){
    int maxx,minn;
    if(l==r) return true;
    maxx=querymax(1,1,n,l+1,r);
    minn=querymin(1,1,n,l+1,r);
    if(maxx>0&&minn>0) return true;
    else return false;
}
bool low(int l,int r){
    int maxx,minn;
    if(l==r) return true;
    maxx=querymax(1,1,n,l+1,r);
    minn=querymin(1,1,n,l+1,r);
    if(maxx<0&&minn<0) return true;
    else return false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) a[i]=b[i]-b[i-1];
    build(1,1,n);
    int m;cin>>m;
    cout<<endl;
    for(int i=1;i<=m;i++){
        int op,l,r,maxx,minn;cin>>op>>l>>r;
        if(op==1){
            int x;cin>>x;
            modify(1,1,n,l,x);
            modify(1,1,n,r+1,-x);
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }else if(op==2){
            if(l==r) {
                cout<<1<<endl;
                continue;
            }
            maxx=querymax(1,1,n,l+1,r);
            minn=querymin(1,1,n,l+1,r);
            if(maxx==0&&minn==0) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(op==3){//
            if(high(l,r)) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(op==4){
            if(low(l,r)) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(op==5){
            int mid=l+r>>1;
            int flag=0;
            while(l<=r){
                int mid=l+r>>1;
                int z=high(l,mid),y=low(mid,r);
                if(z&&y){
                    flag=1;
                    break;
                }
                else if(z){
                    l=mid+1;
                }
                else if(y){
                    r=mid-1;
                }
                else{
                    break;
                }
            }
            if(flag) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}