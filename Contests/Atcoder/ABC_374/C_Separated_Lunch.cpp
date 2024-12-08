#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=inf;
    for(int i=0;i<(1<<n);i++){
        int lsum=0,rsum=0;
        for(int j=1;j<=n;j++){
            int p=1<<(j-1);
            if(i&p) lsum+=a[j];
            else rsum+=a[j];
        }
        ans=min(ans,max(lsum,rsum));
    }
    cout<<ans<<endl;
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