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
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    for(int i=l1;i<=r1;i++){
        a[i]++;
    }
    for(int i=l2;i<=r2;i++){
        a[i]++;
    }
    int cnt=0;
    for(int i=1;i<=100;i++){
        if(a[i]==2) cnt++;
    }
    cnt++;
    if(l1==l2) cnt--;
    if(r1==r2) cnt--;
    cout<<cnt<<endl;
    for(int i=1;i<=100;i++){
        a[i]=0;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}