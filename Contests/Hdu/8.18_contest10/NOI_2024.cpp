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
int n,m,k;
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i]-1;
    }
    sum=min(sum,m-1);
    if(sum<k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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