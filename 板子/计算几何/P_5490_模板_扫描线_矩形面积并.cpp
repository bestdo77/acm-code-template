#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
#define ls k<<1
#define rs k<<1|1
struct line{
    int x1,x2,y;
    int tag;//出入边
    bool operator<(line &t){
        return y<t.y;
    }
}L[N];
struct tree{
    int l,r;//每一块的范围
    int cnt,len;//区间覆盖次数和长度
}tr[N<<3];
int X[N];
void build(int k,int l,int r){
    tr[k]={l,r,0,0};
    if(l==r) return;
    int mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void pushup(int k){
    int l=tr[k].l,r=tr[k].r;
    if(tr[k].cnt) tr[k].len=X[r+1]-X[l];//一直向下找到有覆盖的位置，线段树保证了不会找重复
    else tr[k].len=tr[ls].len+tr[rs].len;
}
void modify(int k,int l,int r,int tag){
    if(l>tr[k].r||r<tr[k].l) return;//一点没覆盖就不去走
    if(l<=tr[k].l&&tr[k].r<=r){//当前点区间被要修改的区间覆盖了
        tr[k].cnt+=tag;
        pushup(k);
        return;
    }
    modify(ls,l,r,tag);
    modify(rs,l,r,tag);
    pushup(k);
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        L[i]={x1,x2,y1,1};
        L[n+i]={x1,x2,y2,-1};//应该是默认y1<y2
        X[i]=x1,X[n+i]=x2;
    }
    n*=2;
    sort(L+1,L+n+1);
    sort(X+1,X+n+1);
    int s=unique(X+1,X+n+1)-X-1;//s是离散化后点的数量
    build(1,1,s-1);//按离散化之后的s建的树
    int ans=0;
    for(int i=1;i<n;i++){
        int l=lower_bound(X+1,X+s+1,L[i].x1)-X;//搜是第几条边
        int r=lower_bound(X+1,X+s+1,L[i].x2)-X;
        modify(1,l,r-1,L[i].tag);//加边
        ans+=tr[1].len*(L[i+1].y-L[i].y);//更新答案，是覆盖的长度乘以体积
    }
    cout<<ans<<endl;
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