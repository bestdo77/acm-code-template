#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
vector<array<int,element>> v;
int a[N],ans[N];
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    bool flag=0;
    int gcdd=__gcd(a[1],a[2]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            gcdd=__gcd(gcdd,a[i]);
    }
    cout <<min(m%gcdd,gcdd-m%gcdd)<<endl;
    // int ans1=inf;
    // for(int i=1;i<=n;i++){
    //     ans[i]=min(m%a[i],a[i]-m%a[i]);
    //     ans1=min(ans1,ans[i]);
    // }
    // if(flag){
    //     cout<<"0"<<endl;
    // }else{
    //     printf("%lld\n",ans1);
    // }
    return 0;
}