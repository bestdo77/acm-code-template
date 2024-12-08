#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    if(n<=k){
        if((n/2+n%2)%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else{
        int st=n-k+1;
        if(st%2==0){//如果是偶数
            if((k/2)%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            k++;
            if((k/2)%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
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