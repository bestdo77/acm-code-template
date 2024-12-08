#include <iostream>
using namespace std;
const int MAX=1e8+10;
using namespace std;
inline void read(int &x){
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=(s*10)+ch-'0';ch=getchar();}
    x=s*w;
}
bool judge[MAX];//0是素数，1不是素数
int prime[MAX];int p=0;
int phi[MAX];//欧拉函数,phi[x]表示1到x中与x互质的数的个数。
int main()
{
    phi[1]=1;
	int n;read(n);
	for(int i=2;i<n;i++)
	{
		if(!judge[i]) prime[++p]=i,phi[i]=i-1;//性质1，对于素数，欧拉函数等于本身减去1。
		for(int j=1;j<=p&&i*prime[j]<=n;j++)
		{
			judge[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
			
				phi[i*prime[j]]=phi[i]*prime[j];//性质2，两个数同余的合数的欧拉函数：余数（素数）乘以素数 
				break;//相比于埃氏筛优化的地方 
			}else
			{
				phi[i*prime[j]]=phi[i]*phi[prime[j]];//互为素数的合数的欧拉函数：两素数欧拉函数之积
			}
		}
	}
	int t;read(t);int x;
	for(int i=0;i<t;i++)
	{
		read(x);
		printf("%d\n",phi[x]);
	}
	return 0;
	
}