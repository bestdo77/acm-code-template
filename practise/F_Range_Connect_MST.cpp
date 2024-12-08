#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=300000;
struct Q{
    int l,r,c;
}a[N];
int pre[N];
void init(int n){//初始化
    for (int i=0;i<=n;i++){
        pre[i]=i;
    }
}
int find(int x){//找到x的pre节点
    // if (pre[x]==x)return x;
    // return pre[x]=find(pre[x]);
    if(x!=pre[x]) return pre[x]=find(pre[x]);//把这个子节点的老大换成老大的老大 
	return pre[x];
}
bool join(int x,int y){//合并
    x=find(x);
    y=find(y);
    if (x==y)return false;
    else pre [x]=y;
    return true;
}
int cmp(Q x,Q y){
    return x.c<y.c;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin >>n>>q;
    
    for (int i=1;i<=q;i++){
        cin >>a[i].l>>a[i].r>>a[i].c;
    }
    sort (a+1,a+1+q,cmp);
    int ans=0;
    init (n);
    for (int i=1;i<=q;i++){
        //cout <<a[i].l<<" "<<a[i].r<<" "<<a[i].c<<endl;
        ans+=a[i].c;
        for (int j=find(a[i].l);j<a[i].r;j=find(j)){
            join(j,j+1);
            pre[j]=j+1;
            ans+=a[i].c;
        }
    }

    
    if (find(1)!=n)cout <<-1<<endl;
    else cout <<ans<<endl;
}