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
pii a[N];
vector<int> G[N];
deque<pii> q;
bool vis[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    int last=0;
    random_shuffle(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(a[i].first!=last){
            cout<<a[i].second<<endl;
            last=a[i].first;
            vis[i]=1;
            continue;
        }
        for(int j=n;j>=1;j--){
            if(a[j].first==last) continue;
            if(vis[j]) continue;
            last=a[i].first;
            cout<<a[j].second<<endl;
            cout<<a[i].second<<endl;
            vis[j]=vis[i]=1;
            break;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}