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
    vector<pii> a;
    int pos=0;
    int sz=n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(make_pair(x,i));
    }
    for(int i=0;i<n-1;i++){
        pos%=sz;
        pos+=a[pos].first-1;
        pos%=sz;
        sz--;
        a.erase(a.begin()+pos);
        pos++;
    }
    cout<<a[0].second<<endl;
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