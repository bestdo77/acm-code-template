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
int a[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int x,y,k;cin>>x>>y>>k;
    if(x==0&&y==0){
        cout<<0<<endl;
        return;
    }
    int mx=max(x/k+(x%k!=0),y/k+(y%k!=0));
    if(x/k+(x%k!=0)>y/k+(y%k!=0)) cout<<mx+mx-1<<endl;
    else cout<<2*mx<<endl;
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