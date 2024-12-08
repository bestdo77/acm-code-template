#include <bits/stdc++.h>
using namespace std;
struct node{
	char left,right;
}t[30];
int n,root;
void pre_order(int x){//前序遍历，根左右的方式，正常写dfs,其它也是一样，就是改变dfs的顺序。
	cout<<char(x+'`');
	if(t[x].left!='*'-'`') pre_order(t[x].left);
	if(t[x].right!='*'-'`') pre_order(t[x].right); 
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		t[s[0]-'`'].left=s[1]-'`';
		t[s[0]-'`'].right=s[2]-'`';
		if(i==1) root=s[0]-'`';
	}
	pre_order(root);
	return 0;
} 