#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int pre[2*N];
vector<int> kmod[N];
int cnt[N];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++){
        a[i]+=a[i-1];
    }
    int ans=0;
    // for(int i=1;i<=2*n;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    // for(int i=1;i<=2*n-1;i++){
    //     cout<<a[i]%k<<" ";
    // }cout<<endl;
    // int ans=0;
    for(int i=1;i<=2*n-1;i++){
        int km=a[i]%k;
        int mp=k-km;
        if(i>=n){
            ans+=cnt[km];
            cnt[a[i-n+1]%k]--;
        }
        cnt[km]++;
    }
    cout<<ans<<endl;
    // for(int i=0;i<k;i++){
    //     cout<<i<<": ";
    //     for(auto it:kmod[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<ans<<endl;
    // cout<<1<<endl;
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