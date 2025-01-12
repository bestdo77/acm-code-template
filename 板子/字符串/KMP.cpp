#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'
const int N=1e6+10;
char a[1000010]; // 文本串
char b[1000010]; // 模板串(将被匹配的子串)
int kmp_next[1000010]; // next数组
int ans[1000010],p1=0;
void getNext(int m){//后缀和前缀匹配
	int j = 0;
	// 初始化next[0]的值
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		// 如果这一位匹配，那么将j+1，继续判断下一位
		if(b[i]==b[j]) ++j;
		// 更新next[i]的值
		kmp_next[i] = j;
	}
}//后缀数组一直是

void kmp(int n,int m){
	int i, j = 0;
	// 初始化位置p = -1
	int p = -1;
	// 初始化next数组
	getNext(m);
	for(i=0; i<n; ++i){
		// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		// 如果这一位匹配，那么将j+1，继续判断下一位
		if(b[j]==a[i]) ++j;
		// 如果是子串(m位完全匹配)，则更新位置p的值，并中断程序
		if(j==m){
		 	ans[++p1]=i-m+1;
			//这里直接return 1,可以判断存不存在匹配串
		 	j=kmp_next[j-1];
		}
	}
	// 返回位置p的值
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>a>>b;
	int n=strlen(a);
	int m=strlen(b);
	getNext(m);
	kmp(n,m);
	for(int i=1;i<=p1;i++) cout<<ans[i]+1<<endl;//每个匹配的位置
	for(int i=0;i<m;i++) cout<<kmp_next[i]<<" ";
	cout<<endl;	
	return 0;
} 