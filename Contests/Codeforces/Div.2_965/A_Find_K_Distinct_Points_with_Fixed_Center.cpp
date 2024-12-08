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
    int x,y,k;
    cin>>x>>y>>k;
    if(k%2){
        cout<<x<<" "<<y<<endl;
        k--;
    }
    for(int i=10000;i>=0;i--){
        for(int j=10000;j>=0;j--){
            if(i==x&&j==y) continue;
            if(k==0) break;
            cout<<i<<" "<<j<<endl;
            cout<<2*x-i<<" "<<2*y-j<<endl;
            k-=2;
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