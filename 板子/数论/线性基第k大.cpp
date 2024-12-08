#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>

using namespace std;

typedef long long ll;

const int MAXN=10005;
int n,q;
ll k,tmp;
struct L_B
{
	ll b[65],p[65];
	int cnt,flag;
	L_B()
	{
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
		cnt=flag=0;
	}
	inline bool insert(ll x)
	{
		for(int i=62;i>=0;--i)
			if(x&(1ll<<i))
			{
				if(b[i])
					x^=b[i];
				else
				{
					b[i]=x;
					return true;
				}
			}
		flag=1;
		return false;
	}
	ll get_max()
	{
		ll ret = 0;
		for(int i=62;i>=0;--i)
			if((ret^b[i])>ret)
				ret^=b[i];
		return ret;
	}
	ll get_min()
	{
		if(flag)
			return 0;
		for(int i=0;i<=62;++i)
			if(b[i])
				return b[i];
		return 0;
	}
	inline void rebuild()
	{
		for(int i = 1;i <= 62;++i)
			if(b[i])
				for(int j=0;j<i;++j)
					if(b[i]&(1ll<<j))
						b[i]^=b[j];
		for(int i=0;i<=62;++i)
			if(b[i])
				p[cnt++]=b[i];
	}
	ll kth(ll k)
	{
		if(flag)
			--k;
		if(k==0)
			return 0;
		ll ret = 0;
		if(k>=(1ll<<cnt))
			return -1;
		for(int i=0;i<=cnt-1;++i)
			if(k&(1ll<<i))
				ret^=p[i];
		return ret;
	}
};
/*
L_B merge(const L_B &n1,const L_B &n2)
{
	L_B ret = n1;
	for(int i = 0;i <= 62;++i)
		if(n2.b[i])
			ret.insert(n2.b[i]);
	ret.flag = n1.flag | n1.flag;
	return ret;
}
*/
int main()
{
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;++Case)
	{
		L_B lis;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
		{
			scanf("%lld",&tmp);
			lis.insert(tmp);
		}
		scanf("%d",&q);
		lis.rebuild();
		printf("Case #%d:\n",Case);
		while(q--)
		{
			scanf("%lld",&k);	
			printf("%lld\n",lis.kth(k));
		}
	}
	return 0;
}
