#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int n,m;
int x[N],y[N];
int px[N],py[N];
int s[N];
void solve(){
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    for(int i=1;i<=n;i++){
        px[i]=px[i-1]+x[i];
        py[i]=py[i-1]+y[i];
    }
    for(int i=-2e6;i<=2e6;i++){
        int id=upper_bound(x+1,x+1+n,i)-x;
        int tt=(px[n]-px[id-1]-(n-id+1)*i)+((id-1)*i-px[id-1]);
        if(tt<=d){
            s[tt]++;
        }
    }
    for(int i=1;i<=d;i++){
        s[i]+=s[i-1];
    }
    int ans=0;
    for(int i=-2e6;i<=2e6;i++){
        int id=upper_bound(y+1,y+1+n,i)-y;
        int tt=(py[n]-py[id-1]-(n-id+1)*i)+((id-1)*i-py[id-1]);
        if(tt<=d){
            ans+=s[d-tt];
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}