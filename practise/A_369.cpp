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
    int x1,x2;cin>>x1>>x2;
    int ans=0;
    if(x1>x2) swap(x1,x2);
    if(x1==x2) cout<<1<<endl;
    else{
        bool flag=0;
        for(int i=x1;i<=x2;i++){
            if(i-x1==x2-i) flag=1;
        }
        cout<<(int)(2+flag)<<endl;
    }
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