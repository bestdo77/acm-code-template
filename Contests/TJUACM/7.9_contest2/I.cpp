#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=5e5+10;
int n,m,k;
struct node{
    int u,v,w;
    bool operator < (const node &a) const{
        return w<a.w;
    }
}a[MAX];
int f[MAX],vis[MAX];
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}//初始化掌门。掌门是他自己
}
 
int find_f(int x){
	if(x!=f[x]) return f[x]=find_f(f[x]);//把这个子节点的老大换成老大的老大 
	return f[x]; 
}//压缩路径 
 
void join(int x,int y){
	int fx=find_f(x);
	int fy=find_f(y);
	if(fx!=fy) f[fy]=fx;
}//合并子集
int check(int d){
    int cnt=0;
    init(n);
    for(int i=1;i<=m;i++){
        if(a[i].w-d>0){//如果当前边权大于d，那么就跳过这个点
            continue;
        }
        join(a[i].u,a[i].v);//合并两个子集
    }
    for(int i=1;i<=n;i++){
        if(find_f(i)==i) cnt++;//统计连通块个数
    }  
    return cnt;//说明d很小，要找大的
}
bool checkans(int d){
    int cnt=0;
    init(n);
    for(int i=1;i<=m;i++){
        if(a[i].w-d>0){//如果当前边权大于d，那么就跳过这个点
            continue;
        }
        join(a[i].u,a[i].v);//合并两个子集
    }
    for(int i=1;i<=n;i++){
        if(find_f(i)==i) cnt++;//统计连通块个数
    }  
    return cnt==k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
            cin>>a[i].u>>a[i].v>>a[i].w;
        }
        sort(a+1,a+1+m);
        int min=0,max=a[m].w+1,ans=-1;
        int l=min-1,r=max+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            int p=check(mid);
            if(p<=k){
                r=mid;
                if(p==k) ans=mid;   
            }
            else if(p>k) l=mid;
            //else l=mid;二分找最小
        }
        cout<<l<<" "<<r<<endl;
        cout<<ans<<'\n';
    }
	return 0;
}
