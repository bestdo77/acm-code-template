#include <bits/stdc++.h>
using namespace std;
int main(){
    set<string> st;
    for(int i=1;i<=72;i++){
        string s;cin>>s;
        st.insert(s);
    }
    cout<<st.size()<<endl;
}