#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl "\n"
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
map<int,int> vis;
int even[N],odd[N];
void solve(){
    vis.clear();
    // cout<<vis.size()<<endl;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i%2) odd[i]=odd[i-1]+a[i],even[i]=even[i-1];
        else odd[i]=odd[i-1],even[i]=even[i-1]+a[i];
    }
    vis[0]=1;
    for(int i=1;i<=n;i++){
        if(!vis[odd[i]-even[i]]) vis[odd[i]-even[i]]=1;
        else{
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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