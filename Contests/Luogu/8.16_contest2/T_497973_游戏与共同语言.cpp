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
void solve(){
    int x1,y1,z1,x2,y2,z2;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    if(x1>x2) cout<<"A"<<endl;
    else if(x1<x2) cout<<"B"<<endl;
    else{
        if(y1>y2) cout<<"A"<<endl;
        else if(y1<y2) cout<<"B"<<endl;
        else{
            if(z1<z2) cout<<"A"<<endl;
            else if(z1>z2) cout<<"B"<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}