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
		if(a[i]<a[j]) b[k++]=a[i++];
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
	long long int a[n];
	long long int (*p)=a;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	msort(a,0,n-1);
	for(i=0;i<n-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[i]<<endl;
	return 0;
}