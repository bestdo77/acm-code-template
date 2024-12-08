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
int d[N],dis[N];
queue<int> q;
vector<int> G[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) d[i]=dis[i]=0;
    for(int i=1;i<=n-1;i++){
        G[i].push_back(i+1);
    }
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
    }
    q.push(1);
    for(int i=1;i<=n;i++) d[i]=inf;
    d[1]=0;
    for(int i=1;i<=n;i++){
        for(auto y:G[i]){
            d[y] = min(d[y], d[i] + 1);
            int l=i+1;
            int r=y-d[y]-1;
            if(l<=r){
                dis[l]++;
                dis[r+1]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis[i]+=dis[i-1];
    }
    for(int i=1;i<=n-1;i++){
        if(dis[i]>0) cout<<0;
        else cout<<1;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
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