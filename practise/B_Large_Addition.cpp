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
    string s;cin>>s;
    bool flag=1;
    if(s[0]!='1') flag=0;
    for(int i=1;i<s.length()-1;i++){
        if(s[i]=='0') flag=0;
    }
    if(s[s.length()-1]=='9') flag=0;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl; 
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}