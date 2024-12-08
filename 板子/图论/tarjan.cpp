#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000];
void msort(int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	msort(l,mid);
	msort(mid+1,r);
	
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	
	while(i<=mid) b[k++]=a[i++];
	while(j<=r)   b[k++]=a[j++];
	
	for(i=l;i<=r;i++) a[i]=b[i]; 
}
int main()
{
	int n;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	msort(0,n);
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}