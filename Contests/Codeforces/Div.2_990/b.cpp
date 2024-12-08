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
    int n;cin>>n;
    vector<int> ch(26,0);
    string s;cin>>s;
    for(auto it:s){
        ch[it-'a']++;
    }
    char ex='a'+(max_element(ch.begin(),ch.end())-ch.begin());
    int mn=inf;
    for(int i=0;i<26;i++){
        if(ch[i]!=0&&ch[i]<mn){
            mn=ch[i];
        }
    }
    for(int i=0;i<s.size();i++){
        if(ch[s[i]-'a']==mn&&s[i]!=ex) {
            s[i]=ex;
            break;
        }
    }
    cout<<s<<endl;
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