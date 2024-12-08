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
    int ans=-1;
    for(int i=0;i<min(s.size(),t.size());i++){
        if(s[i]!=t[i]) break;
        ans=i;
    }
    if(ans==-1) cout<<s.size()+t.size()<<endl;
    else{
        cout<<s.size()+t.size()-ans<<endl;
        // cout<<1<<endl;
    }
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