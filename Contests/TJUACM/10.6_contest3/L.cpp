#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
vector<int> a[10];
void Atomatic_AC_machine(){
    string s,tmp="";cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(st.empty()||(st.top()=='('&&s[i]=='(')) st.push(s[i]);
        else st.pop();
        tmp.push_back(s[i]);
        if(st.size()==0) break; 
    }
    // cout<<tmp<<endl;
    if(s.size()%tmp.size()==0){
        string ans="";
        while(ans.size()!=s.size()){
            ans+=tmp;
        }
        // cout<<ans<<endl;
        if(ans==s){
            cout<<"no"<<endl;
        }else{
            cout<<s.substr(tmp.size())+tmp<<endl;
        }
    }else{
        cout<<s.substr(tmp.size())+tmp<<endl;
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