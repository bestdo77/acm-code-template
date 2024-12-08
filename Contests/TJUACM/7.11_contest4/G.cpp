#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
#define ll long long
const int mod=1e10+7;
ll quickpow(ll x,ll y,ll mod)
{
	ll re=1;
	while(y!=0)
	{
		if(y%2==1) re=re*x%mod;
		
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int cnt=0;
        char first=s[0],last=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==first&&s[i]==last){
                cnt++;
            }else if(s[i]>first){
                last=s[i];
            }else if(s[i]<first){
                first=s[i];
            }
        }
        cout<<quickpow(2,cnt,mod)<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int MAXN=1e3+10;
#define ll long long
ll quickpow(ll x,ll y,ll mod)
{
	ll re=1;
	while(y!=0)
	{
		if(y%2==1) re=re*x%mod;
		
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,p;
        cin>>a>>p;
        int flag=quickpow(a,(p-1)/2,p);
        if(flag) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}