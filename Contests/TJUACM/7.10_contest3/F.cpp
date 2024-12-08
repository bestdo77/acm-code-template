#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=1e3+10;
int a[MAXN],b[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;cin>>t;
    while(t--){
       int n,m;cin>>n>>m;
       int ans=0;
       for(int i=1;i<=n;i++){
            cin>>a[i];
       }
       for(int i=1;i<=n;i++){
            if(m>=a[i]) m-=a[i];
            else{
                ans+=a[i]-m;
                m=0;
            }
       }
       cout<<ans<<endl;
    }
    return 0;
}