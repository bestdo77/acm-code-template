#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
int a[N],b[N],c[N],d[N];
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],d[i]=b[i];
    sort(a+1,a+1+n),sort(b+1,b+1+n);
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*min(a[i],b[i]))%mod;
    }
    cout<<ans<<" ";
    for(int t=1;t<=m;t++){
        // cout<<0<<endl;
        int op,x;cin>>op>>x;
        if(op==1){ //modify a
            int tp=upper_bound(a+1,a+1+n,c[x])-a-1;//to
            if(a[tp]<b[tp]){
                ans=(ans*quickpow(a[tp],mod-2))%mod;
                ans=(ans*(a[tp]+1))%mod;
            }
            a[tp]++;c[x]++;
        }else{
            int tp=upper_bound(b+1,b+1+n,d[x])-b-1;
            if(b[tp]<a[tp]){
                ans=(ans*quickpow(b[tp],mod-2))%mod;
                ans=(ans*(b[tp]+1))%mod;
            }
            b[tp]++,d[x]++;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}