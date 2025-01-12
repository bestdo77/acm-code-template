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
    stack<string> st;
    for(int i=1;i<=n;i++){
        string op;cin>>op;
        if(op=="push"){
            string v;cin>>v;
            st.push(v);
        }else if(op=="query"){
            if(st.empty()){
                cout<<"Anguei!"<<endl;
            }else{
                cout<<st.top()<<endl;
            }
        }else if(op=="pop"){
            if(!st.empty()) st.pop();
            else{
                cout<<"Empty"<<endl;
            }
        }else{
            cout<<st.size()<<endl;
        }
    }
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