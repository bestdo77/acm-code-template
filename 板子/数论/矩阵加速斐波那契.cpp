#include <iostream>
using namespace std;
#define ll long long
const ll mod=1e9+7;
struct matrix
{
	ll sqr[2][2];
}a,f,x;

matrix operator*(matrix a,matrix b)
{
	matrix c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			//第i行乘第j列 
			c.sqr[i][j]=(a.sqr[i][0]%mod*b.sqr[0][j]%mod)%mod+(a.sqr[i][1]%mod*b.sqr[1][j]%mod)%mod;
             c.sqr[i][j]%=mod;
		}
		return c;
}

void quickpow(matrix &x,ll y)
{
	matrix I;
	I.sqr[0][0]=I.sqr[1][1]=1;
	I.sqr[0][1]=I.sqr[1][0]=0;
	while(y)
	{
		if(y%2==1) I=I*x;
		
		x=x*x,y/=2;
	}
	x=I;
}

int main()
{
	f.sqr[0][0]=2;f.sqr[0][1]=1;
	x.sqr[0][1]=x.sqr[0][0]=x.sqr[1][0]=1;
	ll int n;cin>>n;
	quickpow(x,n-1);
	f=x*f;
	cout<<f.sqr[0][1]%mod<<endl;
	return 0;
}
