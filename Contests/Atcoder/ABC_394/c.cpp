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

void Atomatic_AC_machine(){
    string s;cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i-1]=='W'&&s[i]=='A'){
            s[i-1]='A';
            s[i]='C';
            for(int j=i-2;j>=0;j--){
                if(s[j]=='W'){
                    s[j]='A';
                    s[j+1]='C';
                }else break;
            }
        }
    }
    cout<<s<<endl;
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