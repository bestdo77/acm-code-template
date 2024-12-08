#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    int days=0;
    for(int i=1;i<=m;i++){
        int nums=0;
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            if(x==k) nums++;
        }
        if(nums*2>=n) days++;
    }
    if(days*2>=m) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}