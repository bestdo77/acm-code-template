#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string s;
void Atomatic_AC_machine(){
    cin >>s;
    s+="&&";
    for (int i=0;i<s.length();i++){
        s[i]+=32;
    }
    for (int i=0;i<s.length();i++){
        if (s[i]=='s'&&s[i+1]=='s'&&s[i+2]=='s'){
            for (int j=0;j<s.length()-2;j++)cout <<s[j];
            cout <<endl;
            for (int j=0;j<i;j++)cout <<s[j];
            cout <<'B';
            for (int j=i+2;j<s.length()-2;j++)cout <<s[j];
            cout <<endl;
            for (int j=0;j<=i;j++)cout <<s[j];
            cout <<'B';
            for (int j=i+3;j<s.length()-2;j++)cout <<s[j];
            return;
        }else if (s[i]=='s'&&s[i+1]=='s'){
             for (int j=0;j<s.length()-2;j++)cout <<s[j];
            cout <<endl;
            for (int j=0;j<i;j++)cout <<s[j];
            cout <<'B';
            for (int j=i+2;j<s.length()-2;j++)cout <<s[j];
            cout <<endl;
            return;
        }
    }
    for (int j=0;j<s.length()-2;j++)cout <<s[j];
    cout <<endl;
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