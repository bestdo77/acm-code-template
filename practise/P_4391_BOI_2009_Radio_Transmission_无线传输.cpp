#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int kmp_next[N];
char b[N];
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
}
void solve(){
    int n;cin>>n;
    cin>>b;
    getNext(n);
    for(int i=0;i<n;i++){
        cout<<kmp_next[i]<<" ";
    }cout<<endl;
    int len=0;
    cout<<n-kmp_next[n-1]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; 
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}