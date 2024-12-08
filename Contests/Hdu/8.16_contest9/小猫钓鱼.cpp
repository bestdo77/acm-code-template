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
int a[N],b[N];
vector<int> G[N];
void solve(){
    int n;cin>>n;
    int cnta=0,cntb=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[x]++;
        if(a[x]==2) cnta++;
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        b[x]++;
        if(b[x]==2) cntb++;
    }
    if(cnta==0) cout<<"sha7dow"<<endl;
    else cout<<"shuishui"<<endl;
    for(int i=1;i<=n;i++){
        a[i]=b[i]=0;
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