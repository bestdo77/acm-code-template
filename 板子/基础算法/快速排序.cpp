#include <iostream>

using namespace std;
void quicksort(int left,int right)
{
	int temp,i,j,t;//i，j都是走动的数字，t是交换数字存的数，temp暂存基准点
	if(left>right) return;
	i=left;
	j=right;
	
	int flag=p[(left+right)/2];
	do
	{
		while(p[i]<flag)i++;
		while(p[j]>flag)j--;
		if(i<=j)
		{
			temp=p[i];p[i]=p[j];p[j]=temp;
			i++;j--;
		}
	}while(i<=j);
	if(left<j) quicksort(p,left,j);
	if(right>j) quicksort(p,i,right);
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
	quicksort(a,0,n-1);
	for(i=0;i<n-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[i]<<endl;
	return 0;
}
