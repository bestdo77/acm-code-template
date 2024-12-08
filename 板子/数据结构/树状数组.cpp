//树状数组查询点的时候，可以构建差分数组，树状数组其实就是高级的前缀和数组
//按位log
//mex:从0开始集合中最小未出现元素,最大子段和
int s[510000];
int n;
int lowbit(int x){
	return x&-x;
}
 
void change(int x,int k)
{
	while(x<=n) s[x]+=k,x+=lowbit(x);
}
 
int query(int x){//查询区间和 
	int t=0;
	while(x) t+=s[x],x-=lowbit(x);
	return t;
}	