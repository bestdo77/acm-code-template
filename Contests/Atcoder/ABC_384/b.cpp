#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
bool check1(int x){
    return (x>=1600&&x<=2799);
}
bool check2(int x){
    return (x>=1200&&x<=2399);
}
void Atomatic_AC_machine(){
    int n,t;cin>>n>>t;
    for(int i=1;i<=n;i++){
        int d,v;cin>>d>>v;
        if(d==1){
            if(check1(t)) t+=v;
        }else{
            if(check2(t)) t+=v;
        }
    }
    cout<<t<<endl;
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