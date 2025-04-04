#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
pair<int,string> a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s;cin>>s;
    int good=0,bad=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o') good++;
        else if(s[i]=='x') bad++; 
    }
    if(good&&!bad){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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