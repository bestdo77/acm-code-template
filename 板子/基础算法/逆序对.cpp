#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int val,pos;
}a[510000];
int s[510000];
int n;
int lowbit(int x){
	return x&-x;
}
void change(int x,int k)
{
	while(x<=n) s[x]+=k,x+=lowbit(x);
}
bool cmp(node x,node y){
	if(x.val==y.val){
		return x.pos>y.pos;
	}else return x.val>y.val;
}
int query(int x){//查询区间和 
	int t=0;
	while(x) t+=s[x],x-=lowbit(x);
	return t;
}	 
signed main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].val;a[i].pos=i;
		}
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n;i++){
			change(a[i].pos,1);
			sum+=query(a[i].pos-1);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}