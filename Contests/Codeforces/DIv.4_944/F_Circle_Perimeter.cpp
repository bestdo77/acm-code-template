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
int a[N],n;
bool check(int k,int i){
    return k*k+i*i<n*n;
}
bool check1(int k,int i){
    return k*k+i*i<(n+1)*(n+1);
}
void solve(){
    cin>>n;
    int ans1=0;
    for(int i=1;i<=n;i++){
        int l=-1,r=2e5+1;
        int ans=0;
        while(l+1<r){
            int mid=l+r>>1;
            if(check(mid,i)) l=mid;
            else r=mid;
        }
        ans=l;
        l=-1,r=2e5+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(check1(mid,i)) l=mid;
            else r=mid;
        }
        ans=l-ans;
        ans1+=ans;
    }
    ans1*=4;
    cout<<ans1<<endl;
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