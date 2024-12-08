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
void solve(){
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    int ans=0;
    for(int i=1;i<=m;i++){
        int c;cin>>c;
        int last=0;
        for(int j=1;j<=c;j++){
            int x;cin>>x;
            if(x==l) last=l;
            if(x==r&&last==l){
                ans++;
                last=0;
            }
        }
    }
    cout<<ans<<endl;
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