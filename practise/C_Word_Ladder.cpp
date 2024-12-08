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
map<char,char> mp;
void Atomatic_AC_machine(){
    string s,t;cin>>s>>t;
    vector<string> ans;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]&&s[i]>t[i]){
            s[i]=t[i];
            ans.push_back(s);
        } 
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]!=t[i]&&s[i]<t[i]){
            s[i]=t[i];
            ans.push_back(s);
        } 
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
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