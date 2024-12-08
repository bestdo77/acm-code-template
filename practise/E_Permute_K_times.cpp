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
int n;
vector<int> mul(vector<int>&a,vector<int>&x){//对b进行a操作
    vector<int> ret(n+1,0);   
    for(int i=1;i<=n;i++){
        ret[i]=a[x[i]];
    }
    return ret;
}
void solve(){
    int k;
    cin>>n>>k;
    vector<int> x(n+1,0),a(n+1,0);
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    while(k){
        if(k&1) a=mul(a,x);
        x=mul(x,x),k/=2;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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