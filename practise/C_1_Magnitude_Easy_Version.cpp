#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
// int dp[N][N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mn=inf,pos=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(mn>sum) mn=sum,pos=i;
    }
    if(mn<0) mn=-mn;
    for(int i=pos+1;i<=n;i++){
        mn+=a[i];
    }
    cout<<mn<<endl;
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