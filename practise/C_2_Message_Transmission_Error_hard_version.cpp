#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define ull unsigned long long
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
const int p=97;
int pre[N],suf[N],mip[N];
ull pre1[N],suf1[N],mip1[N];
void Atomatic_AC_machine(){
    mip[0]=mip1[0]=1;
    for(int i=1;i<=4e5;i++){
        mip[i]=mip[i-1]*p%mod;
    }for(int i=1;i<=4e5;i++){
        mip1[i]=mip1[i-1]*p;
    }
    string s;cin>>s;
    int len=s.length();
    s=" "+s;
    for(int i=1;i<=len;i++){
        pre[i]=(pre[i-1]*p%mod+s[i]-'a')%mod;
    }
    for(int i=len;i>=1;i--){
        suf[i]=(suf[i+1]+mip[len-i]*(s[i]-'a')%mod)%mod;  
    }
    for(int i=1;i<=len;i++){
        pre1[i]=(pre1[i-1]*p+s[i]-'a');
    }
    for(int i=len;i>=1;i--){
        suf1[i]=(suf1[i+1]+mip1[len-i]*(s[i]-'a'));  
    }
    // for(int i=1;i<=len;i++){
    //     cout<<pre[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=len;i++){
    //     cout<<suf[i]<<" ";
    // }cout<<endl;
    for(int i=len/2+1;i<=len-1;i++){
        if(pre[i]==suf[len-i+1]){
            cout<<"YES"<<endl;
            cout<<s.substr(1,i)<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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