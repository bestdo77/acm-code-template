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
int b[N];
vector<int> G[N];
void solve(){
    int n,ans=0;cin>>n;
    int nowd=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int p=1,cnt=0;
    int last=-inf;
    for(int i=2;i<=n;i++){
        if(b[i]!=last) ans+=p*(p+1)/2,cnt++,p=2,last=b[i];
        else p++;
    }
    // cout<<p<<endl;
    ans+=p*(p+1)/2;
    // if(cnt==0) cnt++;
    cout<<ans-cnt<<endl;
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