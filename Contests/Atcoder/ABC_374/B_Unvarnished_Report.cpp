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
    string s,t;cin>>s>>t;
    if(s.size()>t.size()) swap(s,t);
    while(s.size()!=t.size()){
        s.push_back('0');
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<0<<endl;
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