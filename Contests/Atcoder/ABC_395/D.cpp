#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[1000010];
struct order{
	int s,j,d;
};
order a[100010];
int delta[1000010];
bool deal(int x)
{
	for(int i=1;i<=n;i++)
	delta[i]=r[i]-r[i-1];
	for(int i=1;i<=x;i++)
	{
		delta[a[i].s]-=a[i].d;
		delta[a[i].j+1]+=a[i].d;
	}
	long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=delta[i];
		if(sum<0)
		return false;
	}
	return true;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>r[i];
	for(int i=1;i<=m;i++)
	cin>>a[i].d>>a[i].s>>a[i].j;
	int l=1,r=m+1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(deal(mid))
		l=mid+1;
		else
		r=mid;
	}
	if(l==m+1)
	cout<<'0';
	else
	cout<<"-1\n"<<l;
	return 0;
}