#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;
int p=37;
int mod=1e9+7;
string a,b;
map<int,int>mp;
int qpow(int x,int y){
    int re=1;
    while (y){
        if(y%2==1)re=re*x%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
signed main (){
    int sb=1,cnm=3;
    cout<<(sb*=cnm)<<endl;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    hash<string> h;
    while (t--){
        cin >>a>>b;
        int len=a.length();
        a+=a;
        mp.clear();
        int now=0;
        for(int i=0;i<len;i++){
            (now+=qpow(p,len-i-1)*(a[i]-'A'+1))%=mod;
        }
        mp[now]=1;
        for (int i=1;i<len;i++){
            (now-=(a[i-1]-'A'+1)*qpow(p,len-1))%=mod;
            (now*=p)%=mod;
            now+=(a[i+len]-'A'+1);
            now=(now%mod+mod)%mod;
            mp[now]=1;
            cout<<now<<endl;
        }
        int ans=0;
        int lenb=b.length();
        now=0;
        for(int i=0;i<len;i++){
            (now+=qpow(p,len-i-1)*(b[i]-'A'+1))%=mod;
        }
        if(mp[now]) ans++;
        for (int i=1;i<lenb-len+1;i++){
            (now-=(b[i-1]-'A'+1)*qpow(p,len-1))%=mod;
            (now*=p)%=mod;
            now+=(b[i+len]-'A'+1);
            now=(now%mod+mod)%mod;
            cout<<now<<endl;
            if(mp[now]) ans++;
        }
        cout <<ans<<endl;
    }
}