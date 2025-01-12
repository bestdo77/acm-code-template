#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n;cin>>n;
    int l=1,r=n;
    string s;cin>>s;
    s=" "+s;
    int ls=0,rp=n+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='s') ls=max(ls,i);
        else if(s[i]=='p') rp=min(rp,i);
    }
    if(ls!=0&&rp!=n+1){
        if(ls>rp){
            cout<<"NO"<<endl;
        }else{
            if(ls==1||rp==n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }else{
        cout<<"YES"<<endl;
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