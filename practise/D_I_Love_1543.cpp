#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string s[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    int cnt=0;
    for(int d=0;d<min(n,m)/2;d++){
        string ss="";
        for(int i=d;i<m-d-1;i++) ss.push_back(s[d][i]);
        for(int i=d;i<n-d-1;i++) ss.push_back(s[i][m-d-1]);
        for(int i=m-d-1;i>=d+1;i--) ss.push_back(s[n-d-1][i]);
        for(int i=n-d-1;i>=d+1;i--) ss.push_back(s[i][d]);
        // cout<<ss<<endl;
        ss+=ss.substr(0,3);
        for(int i=0;i<ss.size()-3;i++){
            if(ss.substr(i,4)=="1543"){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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