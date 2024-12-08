#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int p=a[n];
        int ans=0;
        if(n==2) ans=a[n]-a[1];
        else{
            ans+=a[n]-a[1]-a[2];
            for(int i=3;i<=n;i++){
                ans+=a[n]-a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}