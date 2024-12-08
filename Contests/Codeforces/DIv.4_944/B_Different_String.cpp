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
void solve(){
    string s;cin>>s;
    int p1=0;
    char nt=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=nt){
            s[0]=s[i];
            s[i]=nt;
            cout<<"YES"<<endl;
            cout<<s<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
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