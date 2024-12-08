#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1; 
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string a[N],b[N];
int s[N],t[N];//匹配串和模式串
map<string,int> last;
int kmp_next[N];
bool check(int i,int j){//模式串，匹配串分别到哪了
    return (i-s[i]==j-t[j]||s[i]<i-j&&t[j]==-inf);
}
bool check1(int i,int j){
    return (i-t[i]==j-t[j]||t[i]<i-j&&t[j]==-inf);
}
void getNext(int m){//后缀和前缀匹配
	int j = 0;
	// 初始化next[0]的值
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
		if(check1(i,j)) ++j;
		else{
		    while(j>0 && check1(i,j)) j=kmp_next[j-1];
		}
		// 如果这一位匹配，那么将j+1，继续判断下一位
		// 更新next[i]的值
		kmp_next[i] = j;
	}
}//后缀数组一直是
int kmp(int n,int m){
	int i, j = 0;
	// 初始化位置p = -1
	int p = -1;
	// 初始化next数组
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && !check(i,j)) j=kmp_next[j-1];
		// 如果这一位匹配，那么将j+1，继续判断下一位
		if(check(i,j)) ++j;
		// 如果是子串(m位完全匹配)，则更新位置p的值，并中断程序
		if(j==m){
		 	return i-m+1;
		}
	}
    return -1;
	// 返回位置p的值
}
void Atomatic_AC_machine(){
    int n=0,m=0;
    while(1){
        cin>>a[n++];
        // cout<<a[n-1];
        if(a[n-1]=="$"){
            n--;break;
        }
    }
    while(1){
        cin>>b[m++];
        if(b[m-1]=="$"){
            m--;break;
        }
    }
    for(int i=0;i<n;i++){
        if(last.count(a[i])){
            s[i]=last[a[i]];
        }else{
            s[i]=-inf;
        }
        last[a[i]]=i;
    }//弄主串
    last.clear();
    for(int i=0;i<m;i++){
        if(last.count(b[i])){
            t[i]=last[b[i]];
        }else{
            t[i]=-inf;
        }
        last[b[i]]=i;
    }//弄模式串
    cout<<kmp(n,m)+1<<endl;
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