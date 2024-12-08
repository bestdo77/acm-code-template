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
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxx=*max_element(a+1,a+1+n);
    for(int i=1;i<=q;i++){
        char op;int l,r;
        cin>>op>>l>>r;
        if(maxx>=l&&maxx<=r){
            if(op=='+') maxx++;
            else maxx--;
        }
        cout<<maxx<<" ";
    }
    cout<<endl;
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