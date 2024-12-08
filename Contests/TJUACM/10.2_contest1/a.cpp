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
    int n;cin>>n;
    vector<int> a(n+1),pre(n+2);
    vector<int> but[10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    but[0].push_back(0);
    for(int i=1;i<=n;i++){
        but[pre[i]%10].push_back(i);
    }
    for(int i=0;i<n;i++){
        auto p=upper_bound(but[pre[i]%10].begin(),but[pre[i]%10].end(),i+1);
        if((pre[i+1]-pre[i])%10==0){
            cout<<1<<" ";
            continue;
        }
        if(p==but[pre[i]%10].end()) cout<<-1<<" ";
        else cout<<(*p)-i<<" ";
    }
    cout<<endl;
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