#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int pow2[N];
int a[N];
void Atomatic_AC_machine(){
    pow2[0]=1;
    for(int i=1;i<=32;i++){
        pow2[i]=pow2[i-1]*2;
    }
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=32;j++){
            if(a[i]%pow2[j]!=0){
                ans+=j-1;
                break;
            }
        }
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