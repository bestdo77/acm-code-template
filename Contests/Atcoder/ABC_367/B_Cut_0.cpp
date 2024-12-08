#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void solve(){
    string s;
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='0'){
            s[i]='*';
        }else{
            if(s[i]=='.') s[i]='*';
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='*') break;
        cout<<s[i];
    }
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