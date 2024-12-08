#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
int check(int x){
    for (int i=2;i<sqrt(x)+1;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int ans=0;
    int dp=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp=max(0LL,dp+a[i]);
        ans=max(dp,ans);
    }
    cout<<ans<<endl;
    return 0;
}