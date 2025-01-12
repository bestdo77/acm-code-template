#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
pii a[N];
int n,d;
int qmax(int x){
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,a[i].first*(a[i].second+x));
    }
    return mx;
}
void Atomatic_AC_machine(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=d;i++){
        cout<<qmax(i)<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}