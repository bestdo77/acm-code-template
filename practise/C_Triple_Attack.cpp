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
int a[N];
vector<int> G[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int t=0; 
    t=1;
    for(int i=1;i<=n;i++){
        if(a[i]<=0) continue;
        if(t%3==2) a[i]--,t++;
        if(a[i]<=0) continue;
        if(t%3==0) a[i]-=3,t++;
        // cout<<a[i]<<endl;
        if(a[i]<=0) continue;
        t+=a[i]/5*3;
        if((a[i]%5)>=3) t+=3;
        else t+=a[i]%5;
    }
    cout<<t-1<<endl;
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