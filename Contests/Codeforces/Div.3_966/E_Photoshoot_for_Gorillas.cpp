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
// int a[N];
vector<int> G[N];
priority_queue<int> q;
int c[N];
void solve(){
    while(q.size()) q.pop();
    int n,m,k;cin>>n>>m>>k;
    int a[n+1ll][m+1ll];
    int p;cin>>p;
    for(int i=1;i<=p;i++) cin>>c[i];
    sort(c+1,c+1+p);
    reverse(c+1,c+1+p);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=min({i-0,n-i+1,n-k+1,k});
            int r=min({j-0,m-j+1,m-k+1,k});
            a[i][j]=l*r;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            q.push(a[i][j]);
            cnt++;
            // if(cnt==p) break;
        }
        // if(cnt==p) break;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=p;i++){
        ans+=c[i]*q.top();
        q.pop();
    }
    cout<<ans<<endl;
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