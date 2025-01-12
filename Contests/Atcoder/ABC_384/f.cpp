#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int lowbit(int x){
	return x&-x;
}
int a[N];
bool cmp(int x,int y){
    return lowbit(x)>lowbit(y);
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    int presum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        presum+=a[i];
        ans+=2*((presum+(i)*a[i])/lowbit(a[i]));
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}