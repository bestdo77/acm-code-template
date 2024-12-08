#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
pii b[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    int x0[n+3]{};
    int x1[n+3]{};
    for(int i=1;i<=n;i++) cin>>b[i].first>>b[i].second;
    for(int i=1;i<=n;i++){
        if(b[i].second==0) x0[b[i].first]=1;
        else x1[b[i].first]=1;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(x0[i]&&x1[i]){
            ans+=n-2;
        }
    }
    for(int i=0;i<=n;i++){
        if(x0[i]&&x0[i+2]&&x1[i+1]) ans++;
        if(x1[i]&&x1[i+2]&&x0[i+1]) ans++;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}