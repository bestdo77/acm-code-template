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
priority_queue<int> q;
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        q.push(x);
    }
    // cout<<q.top()<<endl;
    int ans=0;
    while(q.size()>1){
        int x1=q.top();q.pop();
        int x2=q.top();q.pop();
        x1-=x2,ans+=x2;
        if(x1!=0) q.push(x1);
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