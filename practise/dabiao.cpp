#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int dp[N]{1};
#define pii pair<int,int>
map<int,pii> pos;
int search(int x){
    for(int i=x;i>=0;i--){
        if(dp[i]>dp[x]){
            return i;
        }
    }
    return x;
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        if(i%3==0) dp[i]=dp[i/3]+1;
        else dp[i]=dp[i-1]+1;
    }
    int mx=0,mxpos=0;
    for(int i=0;i<=n;i++){
        if(dp[i]>=mx){
            mx=dp[i];
            mxpos=i;
        }
        // pos[mxpos].second++;
        // pos[mxpos].first=mx;
        // cout<<i<<" "<<dp[i]<<" "<<mx<<" "<<mxpos<<endl;
    }
    int l,r;
    cin>>l>>r;
    mx=0;
    for(int i=l;i<=r;i++){
        mx=max(mx,dp[i]);
    }
    cout<<mx<<endl;
    // for(int i=1;i<=n;i++){
    //     if(i%3==2) cout<<i<<" "<<search(i)<<endl;
    // }
}