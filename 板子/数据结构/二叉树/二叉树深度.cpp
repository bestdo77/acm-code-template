#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
struct Node{
	int left;int right;//左右子树编号.如果没有，默认是0。
}t[MAXN];
int n;
int dfs(int x){
	if(!x) return 0;
	return max(dfs(t[x].left),dfs(t[x].right))+1;//会一直走到最下面，走到0后停止，这时候返回1，下面有一个节点，然后再返回往上走
}//dfs里面的数字是递归层数 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].left>>t[i].right;
	}
	cout<<dfs(1)<<endl;
	return 0;
}