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
int vis[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n+1;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vis[a[1]]=1;
    for(int i=2;i<=n;i++){
        if(!vis[a[i]+1]&&!vis[a[i]-1]){
            cout<<"NO"<<endl;
            return;
        }
        vis[a[i]]=1;
    }
    cout<<"YES"<<endl;
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