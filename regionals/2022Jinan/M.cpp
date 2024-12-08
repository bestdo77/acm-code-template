#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[105];
void solve(){
    int n;
    cin >>n;
    for (int i=1;i<=n;i++){
        int tem;
        int cnt=1;
        cin >>tem;
        while (tem){
            a[cnt]+=tem%10;
            tem/=10;
            cnt++;
        }
    }
    for (int i=1;i<=18;i++){
        a[i+1]+=a[i]/10;
    }
    int ans=0;
    for (int i=1;i<=18;i++){
        ans+=a[i]/10;
        a[i]=0;
    }
    cout <<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}