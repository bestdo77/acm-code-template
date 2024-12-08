#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
struct node{
    int p,q,v;
}a[N];
bool cmp(node a,node b){
    return a.q-a.p<b.q-b.p;    
}
int dp[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>a[i].p>>a[i].q>>a[i].v;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=0;i<=m;i++) dp[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=a[i].q;j--){
                dp[j]=max(dp[j-a[i].p]+a[i].v,dp[j]);
            }
        }
        cout<<dp[m]<<endl; 
    }
    return 0;
}