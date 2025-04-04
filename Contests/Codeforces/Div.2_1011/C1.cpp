#include<bits/stdc++.h>
#define int long long
#define double long double
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int inf=1e16;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		// cin>>a>>b;
        a=RNG()%100000,b=RNG()%100000;
		int ans=0;
		if(a==b)
		{
			cout<<-1<<'\n';
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<=35;i++)
		{
		  if(((a>>i)%2)^((b>>i)%2)==1) break;
		 if(((a>>i)%2)==1&&((b>>i)%2)==1)
		{
		  ans+=(1ll<<i);
						a+=(1ll<<i);
						b+=(1ll<<i);
		}
		}
		
		while(l<=35)
		{
		  // cout<<a<<' '<<b<<'\n';
			if(((a>>l)%2)^((b>>l)%2)==1)
			{
				r=l;
				// cout<<r<<" r \n";
			}
			else
			{
				if(((a>>l)%2)==0)
				{
					l++;
				// 	cout<<"ll "<<a<<' '<<b<<'\n';
					continue;
				}
				else
				{
					while(r<l)
					{
						ans+=(1ll<<r);
						a+=(1ll<<r);
						b+=(1ll<<r);
						r++;
					}
 
				}
			}
			l++;
		}
		// cout<<"r "<<r<<'\n';
		// cout<<ans<<"  ans\n";
		if(a+b!=(a^b)){
            cerr<<"NO"<<endl;
            cout<<a-ans<<" "<<b-ans<<endl;
            cout<<bitset<34>(a-ans)<<" "<<bitset<34>(b-ans)<<endl;
            cout<<bitset<34>(a)<<" "<<bitset<34>(b)<<endl;
        }
        if(ans)
		cout<<ans<<'\n';r
		else
		cout<<(1ll<<r)<<'\n';
 
	}
}