#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll ma=1e9+7;
class matrix
{
	public:
		int s;
		int r;
		ll sqr[5][5];
		
	
		matrix(int s,int r)
		{
			this->s=s;
			this->r=r;
			for(int i=1;i<=s;i++){
				for(int j=1;j<=r;j++)
				{
					this->sqr[i][j]=0;
				}
			}
		}
		
		friend matrix operator* (matrix& a,matrix& b)
		{
			matrix c(a.s,b.r);
		/*	for(int i=1;i<=a.s;i++)
			{
				for(int j=1;j<=b.r;j++)
				{
					ll sum=0;
					for(int k=1;k<=a.r;k++)
					{
						sum+=a.sqr[i][k]*b.sqr[k][j];
					}
					c.sqr[i][j]=sum;
				}
			*/
			for(int i=1;i<=a.s;i++) {
    for(int j=1;j<=b.r;j++) {
        ll sum=0;
        for(int k=1;k<=a.r;k++) {
            sum = (sum + a.sqr[i][k] * b.sqr[k][j] % ma) % ma; // 足赤?車?㏒????
        }
        c.sqr[i][j] = sum % ma; // 足赤?車?㏒????
    }
}
			return c;
		}
		
};

void quickpow(matrix& x,ll y)
{
	
	int i=x.s;
	matrix rec(i,i);
	for(int j=1;j<=i;j++)
	{
		rec.sqr[j][j]=1;
	}
	while(y){//米㊣??那y2??a0那㊣?∩DD
		if(y%2==0){//??那y?a??那y那㊣㏒???那y3y辰?2㏒?米℅那y3?辰?2
			y/=2;
			x=x*x; 
		}else{//??那y?a??那y那㊣㏒?﹞?角???那y㏒?ans3?辰?米℅那y
			rec=x*rec; 
			y--;
		}
	} 
	x=rec;
}

int main()
{
	matrix N1(1,2);
	N1.sqr[1][1]=1;
	N1.sqr[1][2]=1;
	matrix tui(2,2);
	tui.sqr[1][1]=0;tui.sqr[1][2]=1;tui.sqr[2][1]=1;tui.sqr[2][2]=1;
	ll n;
	cin>>n;
	quickpow(tui,n-1);
	matrix Nn=N1*tui;
	cout<<Nn.sqr[1][1]%ma<<endl;
}











