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
priority_queue<int,vector<int>,greater<int>> aa[N];
int sg[N];
void solve(){
    int n;cin>>n;
    sg[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=i*2;j<=1e5;j+=i){
            sg[j]=max(sg[i]+1,sg[j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans^=sg[x];
    }
    if(ans) cout<<"Anna"<<endl;
    else cout<<"Bruno"<<endl;
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