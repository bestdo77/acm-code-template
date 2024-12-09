#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    cout<<a[n]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    int d=1;
    int cnt=1;
    a[d]=cnt;
    d=2*d+2;
    cnt++;
    for(int i=2;i<=2e5;i++){
        a[i]=cnt;
        if(i==d){
            d=2*d+2;
            cnt++;
        }
    }
    // for(int i=1;i<=23;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}