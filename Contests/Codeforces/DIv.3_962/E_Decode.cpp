#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];//字符串转换数组
void solve(){
    string s;cin>>s;
    int len=s.length();
    len=s.length(),s=" "+s;
    for(int i=1;i<=len;i++){
        a[i]=a[i-1]+(s[i]=='1'?1:-1);
    }
    int ans=0;
    vector<int> f(2*len+1,0);
    for(int i=0;i<=len;i++){
        int t=a[i]+len;
        ans+=f[t]*(len-i+1)%mod;
        ans%=mod;
        f[t]+=(i+1);
    }
    cout<<ans%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}