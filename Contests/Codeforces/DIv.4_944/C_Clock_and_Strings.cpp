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
bool vis[N];
void solve(){
    for(int i=1;i<=12;i++){
        vis[i]=0;
    }
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a>b) swap(a,b);
    for(int i=a+1;i<b;i++){
        vis[i]=1;
    }
    vis[a]=vis[b]=2;
    if(vis[c]==vis[d]&&vis[c]!=2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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