#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
set<int> st;
void Atomatic_AC_machine(){
    string s="1";
    int idx=0;
    int q;cin>>q;
    int ans=1;
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;
            s.push_back('0'+x);
            ans=((ans*10)%mod+x)%mod;
        }else if(op==2){
            ans=(ans-((s[idx]-'0')*quickpow(10,s.size()-idx-1))%mod+mod)%mod;
            idx++;
        }else{
            cout<<ans<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}