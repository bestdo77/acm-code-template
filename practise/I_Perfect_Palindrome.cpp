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
int c[26];
void solve(){
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        c[s[i]-'a']++;
    }
    cout<<s.size()-*max_element(c,c+26)<<endl;
    for(int i=0;i<26;i++){
        c[i]=0;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    double x=1.5;int y=1;
    cout<<(int)(1.5<=1)<<endl;
    // while(t--){
    //     solve();
    // }
    return 0;
}