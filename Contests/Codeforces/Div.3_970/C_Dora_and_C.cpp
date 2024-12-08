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
int n,x1,x2;
int dis(int x,int y){
    int p=y-x;
    if(x1>x2) swap(x1,x2);
    int yu=x2%x1;
    p=p%x1;
    if(p>=yu&&yu!=0) p=p%yu;
    int ans=p;//小于时候的情况
    if(p!=0){
        int high=((y-x)/x1+1)*x1;
        yu=x1-x2%x1;

    }
    // cout<<x<<" "<<y<<" "<<p<<" "<<yu<<endl;
    return p;
}
void solve(){
    cin>>n>>x1>>x2;
    if(x1>x2) swap(x1,x2);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]%=x1;
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int yu=__gcd(x2,x1);
    int ans=a[n]-a[1];
    for(int i=1;i<=n-1;i++){
        if(yu!=0){
            a[i]+=(a[n]-a[i])/yu*yu;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(yu!=0){
            a[i]+=(a[n]-a[i])/yu*yu;
        }
    }
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    int maxx=*max_element(a+1,a+1+n),minn=*min_element(a+1,a+1+n);
    int p=maxx-minn;
    // cout<<yu<<endl;
    for(int i=1;i<=n-1;i++){
        if(a[i]+yu>a[i+1]) p=min(a[i]+yu-a[i+1],p);
        p=min(a[i]+x1-a[i+1],p);
        p=min(a[i]+x2-a[i+1],p);
    }
    cout<<p<<endl;
    // cout<<endl;
}   
signed main(){
    // cout<<(216087998ll-13106071ll)<<endl;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}