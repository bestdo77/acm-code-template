#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int n,s[N];//维护高度
int h[N],v[N];
int lowbit(int x){
    return x&-x;
}
void change(int x,int k){
    // cout<<k<<endl;
    while(x<=n) s[x]=max(s[x],k),x+=lowbit(x);
}
int query(int x){
    int t=0;
    while(x) t=max(s[x],t),x-=lowbit(x);
    return t;
}
int dp[N];
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        // cout<<h[i]<<" "<<" "<<v[i]<<" "<<query(h[i])<<endl;
        dp[i]=v[i]+query(h[i]);
        // cout<<i<<" "<<" "<<h[i]<<" "<<dp[i]<<endl;
        change(h[i],dp[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<s[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<query(i)<<" ";
    // }cout<<endl;
    cout<<*max_element(dp+1,dp+1+n)<<endl;
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