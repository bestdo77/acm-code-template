#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5100000];
int b[5100000];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans=0x3f3f3f3f;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int j=1;j<=m;j++){
        int x,y,v;cin>>x>>y>>v;
        b[x]+=v;
        b[y+1]-=v;
    }
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        ans=min(ans,b[i]);
    }
    cout<<ans<<endl;
    return 0;
}