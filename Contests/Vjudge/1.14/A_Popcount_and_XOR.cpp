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
    int a,b,c;cin>>a>>b>>c;
    if(a+b<__builtin_popcount(c)){
        cout<<-1<<endl;
        return;
    }
    int x1=0,x2=0;
    for(int i=0;i<60;i++){
        if(c&(1ll<<i)){
            // cout<<i<<endl;
            if(a<b){
                x2+=(1ll<<i);
                b--;
            }else{
                x1+=(1ll<<i);
                a--;
            }
            if(x1<0||x2<0){
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(a!=b){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<60;i++){
        if(!(x1&(1ll<<i))&&!(x2&(1ll<<i))&&a){
            x1+=(1ll<<i);
            x2+=(1ll<<i);
            a--;
        }
    }
    if(a!=0){
        cout<<-1<<endl;
        return;
    }
    // cout<<(x1^x2)<<endl;
    cout<<x1<<" "<<x2<<endl;
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