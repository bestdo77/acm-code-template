#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
ull p=31;
int dp[N];
int last[N];
int a[N];
ull pre[N],suf[N];
ull powk[N];
vector<int> G[N];
void solve(){
    int len1,len2;cin>>len1>>len2;
    string s1,s2;cin>>s1>>s2;
    s1=" "+s1+" ";s2=" "+s2+" ";
    int l=1,r=len1;
    for(int i=1;i<=len2;i++){
        while(l<=len1&&s1[l]!=s2[i]) l++;
        l++;
    }
    for(int i=len2;i>=1;i--){
        pre[i]=pre[i+1]*p+(s2[i]-'a');
        suf[i]=suf[i+1]+(s2[i]-'a')*powk[len2-i];
    }
    int ans=0;
    for(int i=1;i<=len2;i++){
        if(l<=r+1&&pre[i]==suf[i]) ans=(ans+1)%mod;
        // cout<<l<<" "<<r<<endl;
        // cout<<pre[i]<<" "<<suf[i]<<endl;
        while(l<=len1&&s1[r]!=s2[i]) r--;
        r--;
    }
    if(l<=r){
        dp[l-1]=1;
        for(int i=l;i<=r;i++){
            if(last[s1[i]]) dp[i]=((2*dp[i-1]-dp[last[s1[i]]-1])+mod)%mod;
            else dp[i]=2*dp[i-1]%mod;
            last[s1[i]]=i;
        }
        // cout<<dp[r]<<endl;
        ans=(ans+dp[r])%mod;    
    }
    if(r==l-1) ans=(ans+1)%mod;
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    powk[0]=1;
    for(int i=1;i<=1e6;i++){
        powk[i]=powk[i-1]*p;
    }
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}