#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],b[N];
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    int n,t1,t2;cin>>n>>t1>>t2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>t1||b[i]>t2){
            cout<<i<<endl;
            return;
        }
    }
    cout<<n<<endl;
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