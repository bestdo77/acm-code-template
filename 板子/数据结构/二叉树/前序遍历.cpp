#include <bits/stdc++.h>
using namespace std;
struct node{
	int left,right;
}t[1000];
int n,root;
void pre_order(int x){//前序遍历，根左右的方式，正常写dfs,其它也是一样，就是改变dfs的顺序。
	cout<<x<<" ";
	if(t[x].left!=0) pre_order(t[x].left);
	if(t[x].right!=0) pre_order(t[x].right); 
}
void zhong_order(int x){//前序遍历，根左右的方式，正常写dfs,其它也是一样，就是改变dfs的顺序。
	if(t[x].left!=0) zhong_order(t[x].left);
	cout<<x<<" ";
	if(t[x].right!=0) zhong_order(t[x].right); 
}
void hou_order(int x){//前序遍历，根左右的方式，正常写dfs,其它也是一样，就是改变dfs的顺序。
	if(t[x].left!=0) hou_order(t[x].left);
	if(t[x].right!=0) hou_order(t[x].right); 
	cout<<x<<" ";
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		t[i].left=l;
		t[i].right=r;
	}
	pre_order(1);
	cout<<endl;
	zhong_order(1);
	cout<<endl;
	hou_order(1);
	cout<<endl;
	return 0;
} 