#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int cnt[N];
void Atomatic_AC_machine(){
    int x,m;cin>>x>>m;
    int cnt=0;
    for(int i=1;i<=min(2*x,m);i++){//i denote x^y=c,c|x or c|y
        int ans=i^x;
        if(ans==0) continue;
        if(x%ans==0||i%ans==0) cnt++;
    }
    cout<<cnt<<endl;
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