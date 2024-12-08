#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
// #define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
// string s;
int n;
void Atomatic_AC_machine(){
    cin>>n;
    string s;
    while(1){
        s.push_back('0');
        cout<<"? "<<s<<endl;
        int x;cin>>x;
        if(x==0){
            s[s.size()-1]='1';
            cout<<"? "<<s<<endl;
            cin>>x;
            if(x==0){
                s.pop_back();
                break;
            }
        }
        if(s.size()==n){
            cout<<"! "<<s<<endl;
            return;
        }
    }
//    cout<<"!!!"<<endl;
    while(1){
        s='0'+s;
        cout<<"? "<<s<<endl;
        int x;cin>>x;
        if(x==0){
            s[0]='1';
        }
        if(s.size()==n){
            cout<<"! "<<s<<endl;
            return;
        }
    }
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}