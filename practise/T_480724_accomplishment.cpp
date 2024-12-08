#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e3+10;
const int mod=1e9+7;
int a[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=n/3;i++){
        for(int j=1;j<=m/3;j++){
            ans+=a[2+3*(i-1)][2+3*(j-1)];
            // cout<<2+3*(i-1)<<" "<<2+3*(j-1)<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}