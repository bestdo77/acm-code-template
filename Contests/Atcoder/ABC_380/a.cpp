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
    string s;cin>>s;
    int cnt1=0,cnt2=0,cnt3=0;
    for(auto it:s){
        if(it=='1') cnt1++;
        if(it=='2') cnt2++;
        if(it=='3') cnt3++;
    }
    if(cnt1==1&&cnt2==2&&cnt3==3){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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