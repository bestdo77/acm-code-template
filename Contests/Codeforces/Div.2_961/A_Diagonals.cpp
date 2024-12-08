#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<array<int,element>> v;
void solve(){
    int n,m;cin>>n>>m;
    // cout<<n<<" "<<m<<endl;
    int b[2*n+1];
    b[0]=0;
    b[1]=n;
    // cout<<1<<endl;
    for(int i=2;i<=2*n-1;i++){
        b[i]=n-(i/2);
        // cout<<b[i]<<" ";
    }
    // for(int i=1;i<=2*n-1;i++){
    //     cout<<b[i]<<" ";
    // }
    for(int i=1;i<=2*n-1;i++){
        b[i]+=b[i-1];
    }
    for(int i=0;i<=2*n-1;i++){
        // cout<<m<<" "<<b[i]<<endl;
        if(m<=b[i]){
            cout<<i<<endl;
            // cout<<b[i]<<endl;
            return;
        }
    }
    cout<<2*n-1<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        // cout<<t<<endl;
        solve();
    }
    return 0;
}