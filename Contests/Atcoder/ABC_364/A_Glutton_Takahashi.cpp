#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
void solve(){
    int n;cin>>n;
    string last="0";
    for(int i=1;i<=n;i++){
        string tmp;cin>>tmp;
        if(tmp=="sweet"&&last=="sweet"&&i!=n){
            cout<<"No"<<endl;    
            return;
        }
        last=tmp;
    }
    cout<<"Yes"<<endl;
    return;
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