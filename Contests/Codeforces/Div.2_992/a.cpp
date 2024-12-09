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
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(abs(a[i]-a[j])%k==0){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}