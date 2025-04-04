#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
stack<char> st;
void Atomatic_AC_machine(){
    string s;cin>>s;
    for(auto ch:s){
        // if(!st.empty()){
        //     db(st.top())
        //     cendl
        // }
        if(ch=='['||ch=='('||ch=='<'){
            st.push(ch);
        }else{
            if(st.empty()){
                cout<<"No"<<endl;
                return;
            }else{
                if(st.top()=='('&&ch==')') st.pop();
                else if(st.top()=='<'&&ch=='>') st.pop();
                else if(st.top()=='['&&ch==']') st.pop();
                else{
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    if(st.empty()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}