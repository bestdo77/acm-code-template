#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=3e5+10;
const int mod=1e9+7;
int a[N],vis[N];
map<int, int> l,r;
priority_queue<pii> q;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=i-1;
        r[i]=i+1;
        q.push(make_pair(a[i],i));
    }
    int sum=0;
    for(int i=1;i<=k;i++){
        while(!q.empty()&&vis[q.top().second]) q.pop();
        pii now=q.top();
        q.pop();
        if(now.first<=0) break;
        sum+=now.first;
        vis[l[now.second]]=vis[r[now.second]]=1;
        now.first=a[now.second]=a[l[now.second]]+a[r[now.second]]-now.first;
        q.push(now);
        l[now.second]=l[l[now.second]];
        r[now.second]=r[r[now.second]];
        r[l[now.second]]=l[r[now.second]]=now.second;
    }
    cout<<sum<<endl;
    return 0;
}