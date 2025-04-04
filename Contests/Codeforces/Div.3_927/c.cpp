
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
int inv[N1];
void getInv(int mod)
{
	inv[1]=1;
	for(int i=2;i<2000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}
int a[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    string s;cin>>s;
    s=" "+s;
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        if(s[i]=='L'){
            l++;
        }else{
            r--;
        }
    }
    int ans=1;
    vector<int> out;
    for(int i=n;i>=1;i--){
        if(s[i]=='R'){
            r++;
            ans=(ans*a[r])%m;
            out.push_back(ans);
        }else if(s[i]=='L'){
            l--;
            ans=(ans*a[l])%m;
            out.push_back(ans);
        }
    }
    reverse(out.begin(),out.end());
    for(auto it:out){
        cout<<it<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}