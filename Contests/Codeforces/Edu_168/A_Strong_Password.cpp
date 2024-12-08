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
    bool flag=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            if(s[i]=='a') s.insert(i+1,"b");
            else s.insert(i+1,"a");
            flag=1;
            break;
        }
    }
    if(!flag){
        if(s[s.size()-1]=='a') s+='b';
        else s+='a';
    }
    cout<<s<<endl;
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