#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    int id=(1ll<<(n-1));
    if(n>62) id=1e18;
    int l=1,r=n;
    vector<int> ans(n+1,0);
    if(k>(id)&&n<=62){
        cout<<-1<<endl;
        return;
    }
    bitset<210000> s((k-1)<<1);
    for(int i=1;i<=n;i++){
        if(s[n-i]==1){
            ans[r]=i;
            r--;
            k-=id/2;
        }else{
            ans[l]=i;
            l++;
        }
        id/=2;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // cout<<(1ll<<61)<<endl;
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}