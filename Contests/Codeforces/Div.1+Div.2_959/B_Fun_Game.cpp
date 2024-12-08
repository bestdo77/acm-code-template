#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
char Xor(char x,char y){
    if(x==y) return '0';
    else return '1';
}
void solve(){
    int len;cin>>len;

    string s1,s2;cin>>s1>>s2;
    s1=" "+s1,s2=" "+s2;
    bool flag=0;
    for(int i=1;i<=len;i++){
        if(s1[i]=='1'){
            break;
        }
        if(s1[i]!=s2[i]){
            flag=1;break;
        }

    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}