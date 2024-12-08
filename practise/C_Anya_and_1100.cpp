#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string s;
bool check(int l,int r){
    return (s[l]=='1'&&s[l+1]=='1'&&s[r-1]=='0'&&s[r]=='0');
}
void Atomatic_AC_machine(){
    cin>>s;
    int len=s.size();
    s=" "+s;
    int cnt=0;
    for(int i=1;i<=len-3;i++){
        if(check(i,i+3)){
             cnt++;
        }
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int pos,v;cin>>pos>>v;
        int pre=0,now=0;
        for(int j=max(pos-3,0ll);j<=pos&&j+3<=len;j++){
            if(check(j,j+3)) pre=1;
        }
        s[pos]=char(v+'0');
        for(int j=max(pos-3,0ll);j<=pos&&j+3<=len;j++){
            if(check(j,j+3)) now=1;
        }
        cnt+=now-pre;
        if(cnt) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }       
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