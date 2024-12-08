#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned int
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
void Atomatic_AC_machine(){
    string s;cin>>s;
    int len=s.length();
    s=" "+s;
    for(int i=len/2+1;i<=len-1;i++){
        string pre=s.substr(1,i);
        string suf=s.substr(len-i+1);
        if(pre==suf){
            cout<<"YES"<<endl;
            cout<<pre<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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