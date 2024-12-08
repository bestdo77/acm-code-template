#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e3+10;
int f[maxn];
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}//初始化掌门。掌门是他自己
}
 
int find(int x){
	if(x!=f[x]) return f[x]=find(f[x]);//把这个子节点的老大换成老大的老大 
	return f[x]; 
}//压缩路径 
 
void join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) f[fy]=fx;
}//合并子集
 
// 带权
 int Find(int x) {
    if (x != fa[x]) {
        int t = fa[x];        // 将x的父亲临时保存
        fa[x] = Find(fa[x]);  // 这是x的父亲已经变为祖宗
        dis[x] += dis
            [t];  // x原父亲t的距离已经变为到祖宗的距离，x到原父亲距离+原父亲到
                  // 祖宗距离 = x到祖宗距离
    }
    return fa[x];
}
int main(){
	return 0;
}