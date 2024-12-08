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
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> deg(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    string s;cin>>s;
    s=" "+s;
    int cnt0=0,cnt1=0,cntw=0,cnt=0;
    for(int i=2;i<=n;i++){
        if(deg[i]==1){
            if(s[i]=='0') cnt0++;
            else if(s[i]=='1') cnt1++;
            else cntw++;
        }else{
            if(deg[i]&&s[i]=='?') cnt++;
        }
    }
    if(s[1]=='1'){
        cout<<(cntw/2)+(cntw%2)+cnt0<<endl;
    }else if(s[1]=='0'){
        cout<<(cntw/2)+(cntw%2)+cnt1<<endl;
    }else{
        if(cnt0>cnt1){
            cout<<cntw/2+cnt0<<endl;
        }else if(cnt0==cnt1){
            if(cnt%2==0){
                cout<<(cntw/2)+cnt1<<endl;    
            }else{
                cout<<(cntw/2)+(cntw%2)+cnt1<<endl;
            }
        }
        else{
            cout<<(cntw/2)+cnt1<<endl;
        }
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