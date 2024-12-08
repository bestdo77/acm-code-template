#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void solve(){
    string s;cin>>s;
    int l=0;
    string s1="ava",s2="avava";
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'&&s[i+1]=='a'){
            string ss=s.substr(l,i-l+1);
            l=i+1;
            // cout<<ss<<endl;
            if(ss!=s1&&ss!=s2){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    string ss=s.substr(l);
    // cout<<ss<<endl;
    if(ss!=s1&&ss!=s2){
                cout<<"No"<<endl;
                return;
    }
    cout<<"Yes"<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}