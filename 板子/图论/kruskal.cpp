#include <iostream>
#include <algorithm>
using namespace std;
struct vec{
	int x,y,z;
	bool operator<(const vec &other)const{
		return z<other.z;
	}
}a[510000];
int n,m;
int f[510000];
int find_f(int x){
	if(f[x]==x) return x;
	return f[x]=find_f(f[x]);
}
void join(int x,int y){
	int fx=find_f(x);
	int fy=find_f(y);
	if(fx!=fy){
		f[fx]=fy;
	}
}
void krusal(){//每次将权最小的边连入并查集，判断是否有环,同时如果连入边的个数小于n-1，说明不连通。
	int cnt=0,ans=0;
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		if(find_f(a[i].x)==find_f(a[i].y)) continue;
		else{
			cnt++,ans+=a[i].z;
			join(a[i].x,a[i].y);
		}
	}
//	cout<<cnt<<endl;
	if(cnt==n-1) cout<<ans<<endl;
	else cout<<"orz"<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	krusal();
	return 0;
} 