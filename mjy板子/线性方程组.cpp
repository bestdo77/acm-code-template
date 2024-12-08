#include <bits/stdc++.h>
using namespace std;

const int N=110;
int main()
{
	double a[N][N];
	int n;
	int flag1=0,flag2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>a[i][j];
		}
	}
	int zhuyuan=1;
	for(int i=1;i<=n;i++)
	{
		int now=zhuyuan;
		for(int j=zhuyuan;j<=n;j++)
		{
			if(abs(a[j][i])>abs(a[zhuyuan][i])) now=j;	//这里加绝对值处理精度 
		}
		if(a[now][i]==0) 
		{
			flag1=1;
			
			continue;
		}
		
		swap(a[now],a[zhuyuan]);
		for(int j=i+1;j<=n+1;j++) {
		a[zhuyuan][j]=a[zhuyuan][j]/a[zhuyuan][i];
	}
		a[zhuyuan][i]=1;
		for(int j=1;j<=n;j++)
		{
			if(zhuyuan==j) continue;
			double div=a[j][i]/a[zhuyuan][i];
			for(int k=i;k<=n+1;k++)
			{
				a[j][k]-=a[zhuyuan][k]*div;
			}
			
		}
		zhuyuan++;
		
	}
	
	for(int i=zhuyuan;i<=n;i++)
	{
		if(a[i][n+1]!=0)
		{
			flag2=1;
		}
	}
	if(flag1&flag2) cout<<-1<<endl;
	else if(flag1==1&&flag2==0) cout<<0<<endl;
	else {
	for(int i=1;i<=n;i++) {
	cout<<"x"<<i<<"="<<fixed<<setprecision(2)<<a[i][n+1]<<endl; }
}
	 }