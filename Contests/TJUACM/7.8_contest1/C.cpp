#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1,sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        r++;
        if(r-l+1>=m){
            ans-=a[l];
            l++;
        }
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}