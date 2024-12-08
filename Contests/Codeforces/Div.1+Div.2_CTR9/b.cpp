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
    string s;cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]) {
            cout<<s.substr(i-1,2)<<endl;
            return;
        }
        if(i>=2&&s[i]!=s[i-1]&&s[i]!=s[i-2]&&s[i-1]!=s[i-2]){
            cout<<s.substr(i-2,3)<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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