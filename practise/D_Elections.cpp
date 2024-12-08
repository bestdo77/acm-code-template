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
int pre[N];
int sufmax[N];
int ans[N];
void solve(){
    int n,unde;
    cin>>n>>unde;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sufmax[n+1]=0;
    for(int i=n;i>=1;i--){
        sufmax[i]=max(a[i],sufmax[i+1]);
    }
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    int pos=0;
    int maxx=0;
    for(int i=1;i<=n;i++){
        if(a[i]>maxx) pos=i,maxx=a[i];
    }
    if(a[1]+unde>=maxx) pos=1;
    for(int i=1;i<=n;i++){
        if(i!=pos){
            if(pre[i]+unde>=sufmax[i]) ans[i]=i-1;
            else ans[i]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    for(int i=1;i<=n;i++) ans[i]=0;

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