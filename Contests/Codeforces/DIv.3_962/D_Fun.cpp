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
void solve(){
    int n,x,cnt;cin>>n>>x;
    int ans=0;
    int high=max((int)sqrt(n)+1,x/3+1);
    for(int i=1;i<=x-2;i++){
        for(int j=1;j<=x-2;j++){
            if(!(i+j+1<=x&&i*j+2<=n)) break;
            int c=min((n-i*j)/(i+j),(x-i-j));
            c=max(c,0ll);
            ans+=c;
        }
    }
    cout<<ans<<endl;
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