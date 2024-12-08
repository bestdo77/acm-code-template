#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int x[N],y[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> a;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    for(int i=1;i<=n;i++){
        ans+=max(x[i],y[i]);
        a.push_back(min(x[i],y[i]));
    }
    ans+=*max_element(a.begin(),a.end());
    cout<<ans<<endl;
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