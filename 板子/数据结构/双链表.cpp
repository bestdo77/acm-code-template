#include <iostream>
#include <map>
using namespace std;
map<int,int> l,r;
int main(){//插入删除都是O(logn)的数据结构
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;cin>>n;
	r[0]=1e9+10;//头节点
	int y=0;//上一个节点
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(i==0&&i!=n-1) l[x]=0,r[0]=x;//判断最左节点
		else if(i==n-1) r[y]=x,l[x]=y,r[x]=1e9+10,l[1e9+10]=x;//判断最右节点
		else l[x]=y,r[y]=x;//中间节点
		y=x;
	}
	
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int jud=0;cin>>jud;
		if(jud==1){
			int x,y;cin>>x>>y;
			l[y]=x,r[y]=r[x],l[r[x]]=y,r[x]=y;//插入就是改掉左右节点
		}
		if(jud==2){
			int x,left,right;cin>>x;//删除也是，把删除的点的左和删除点的右相连
			left=l[x],right=r[x];
			r[left]=right;
			l[right]=left;
		}
	}
	int p=0;
	while(r[p]!=1e9+10){
		cout<<r[p]<<" ";
		p=r[p];
	}
	return 0;
}