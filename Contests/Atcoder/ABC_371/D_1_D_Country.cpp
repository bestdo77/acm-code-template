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
int b[N];
int pre[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+b[i];
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int ll=lower_bound(a+1,a+1+n,l)-a;
        int rr=upper_bound(a+1,a+1+n,r)-a-1;
        cout<<pre
    }
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