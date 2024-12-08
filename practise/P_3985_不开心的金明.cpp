#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e7+10;
const int mod=1e9+7;
int dp[N],n,c;;
struct node{
    int w,v;
    bool operator < (const node &b) const{
        return w<b.w;
    }
}a[N];
int dp01(int l,int r){
    for(int i=0;i<=c;i++) dp[i]=0;
    for(int i=l;i<=r;i++){
        for(int j=c;j>=a[i].w;j--){
            dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
        }
    }
    return dp[c];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].v;
    sort(a+1,a+1+n);
    int ans=0;
    int l=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j].w-a[i].w>3){
                ans=max(ans,dp01(i,j-1));
                l=j;
                break;
            }
        }
    }
    ans=max(ans,dp01(l,n));
    cout<<ans<<endl;
    return 0;
}