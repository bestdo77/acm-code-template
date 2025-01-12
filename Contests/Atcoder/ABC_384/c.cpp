#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int val[5];
bool cmp(string a,string b){
    int va=0,vb=0;
    for(char it:a){
        va+=val[it-'A'];
    }
    for(auto it:b){
        vb+=val[it-'A'];
    }
    if(va==vb) return a<b;
    else return va>vb;
}
void Atomatic_AC_machine(){
    for(int i=0;i<5;i++){
        cin>>val[i];
    }
    vector<string> ans;
    for(int i=0;i<(1<<5);i++){
        string s="";
        for(int j=0;j<5;j++){
            if(i&(1<<j)) s.push_back('A'+j);
        }
        if(s!=""){
            ans.push_back(s);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto st:ans){
        cout<<st<<endl;
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