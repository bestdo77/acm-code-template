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
struct node{
    int aa,bb;
}a[N];
bool cmp(node a,node b){
    return a.bb>b.bb;
}
vector<int> G[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].aa>>a[i].bb;
    }
    sort(a+1,a+1+n,cmp);
    int l=0,r=2e5+1;
    while(l+1<r){
        if(check(mid)){
            
        }
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