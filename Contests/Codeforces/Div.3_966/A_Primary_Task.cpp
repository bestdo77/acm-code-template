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
    if(s.size()<3){
        cout<<"NO"<<endl;
        return;
    }
    int ans=0;
    if(s[0]!='1'||s[1]!='0'){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=2;i<s.size();i++){
        if(s[i]=='0'&&i!=s.size()-1){
            cout<<"NO"<<endl;
            return;
        }
        ans*=10;
        ans+=s[i]-'0';
    }
    // cout<<ans<<endl;
    if(ans>=2){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
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