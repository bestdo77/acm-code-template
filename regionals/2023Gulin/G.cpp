#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    stack<char> st;
    for(auto it:s){
        if(it=='('){
            st.push(it);
        }else{
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
        }
    }
    if(st.size()) cout<<"impossible"<<endl;
    else cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}