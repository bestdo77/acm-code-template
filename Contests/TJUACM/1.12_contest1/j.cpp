#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int pre[N],suf[N];
void Atomatic_AC_machine(){
    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;
    s=" "+s;
    int sz=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        if(s[i]=='x'){
            sz++;
            pre[i]++;
        }
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        if(s[i]=='x'){
            suf[i]++;
        }
    }
    if(m==1){
        int l=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            while(pre[i]-pre[l-1]>k){
                l++;
            }
            ans=max(ans,i-l+1);
        }
        cout<<ans<<endl;
        return;
    }
    if(m==2){
        s=s+s.substr(1);
        // cout<<s<<endl;
        int l=1,ans=0;
        for(int i=1;i<=2*n;i++){
            pre[i]=pre[i-1];
            if(s[i]=='x'){
                pre[i]++;
            }
        }
        for(int i=1;i<=2*n;i++){
            while(pre[i]-pre[l-1]>k){
                l++;
            }
            ans=max(ans,i-l+1);
        }
        cout<<ans<<endl;
        return;
    }
    int cnt=k/sz;
    if(cnt>=m){
        cout<<n*m<<endl;
        return;
    }else if(cnt==m-1){
        int ans=n*(m-2);
        k-=sz*(m-2);
        int mx=0;
        for(int i=n;i>=1;i--){
            if(k<suf[i]){
                break;
            }
            int ll=upper_bound(pre+1,pre+1+n,max(0ll,k-suf[i]))-pre-1;
            mx=max(ll+n-i+1,mx);
        }
        cout<<ans+mx<<endl;
        return;
    }else{
        int ans=n*cnt;
        k-=sz*cnt;
        int mx=0;
        for(int i=n;i>=1;i--){
            if(k<suf[i]){
                break;
            }
            int ll=upper_bound(pre+1,pre+1+n,max(0ll,k-suf[i]))-pre-1;
            mx=max(ll+n-i+1,mx);
        }
        ans+=mx;
        int ans1=n*(cnt-1);
        mx=0;
        k+=sz;
        for(int i=n;i>=1;i--){
            if(k<suf[i]){
                break;
            }
            int ll=upper_bound(pre+1,pre+1+n,max(0ll,k-suf[i]))-pre-1;
            mx=max(ll+n-i+1,mx);
        }
        ans=max(ans,ans1+mx);
        cout<<ans<<endl;
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