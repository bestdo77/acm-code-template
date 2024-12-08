#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
pii a[N];
int n,m;
bool check(int x){
    int att=0;
    for(int i=1;i<=n;i++){
        int t=m/a[i].first;
        if((x-1)/a[i].second+1>t) return true;
        else att+=((x-1)/a[i].second+1)*a[i].first;
    }
    // cout<<att<<endl;
    return att>=m;
}
void solve(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    int l=0,r=1e18+1;
    while(l+1<r){
        int mid=l+r>>1;//找最小
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
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