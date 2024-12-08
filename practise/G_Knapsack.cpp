#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e4+10;
const int mod=1e9+7;
const int element=3;
vector<int> G[N];
pii a[N];
int dp[N1];
int suf[N];
void solve(){
    int n,w,k;cin>>n>>w>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;//w,v
    }
    sort(a+1,a+1+n);
    int ans=0;
    priority_queue<int,vector<int>,greater<int>> q;
    while(q.size()) q.pop();
    int sum=0;
    for(int j=n;j>=1;j--){
        q.push(a[j].second);
        sum+=a[j].second;
        if(q.size()>k){
            sum-=q.top();
            q.pop();
        }
        suf[j]=sum;
    }
    for(int i=1;i<=n;i++){
        for(int j=w;j>=a[i].first;j--){
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
            ans=max(ans,dp[j]+suf[i+1]);
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}