#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int n,m;
string mp[N1];
int check(int i,int j){
    int x=0;
    while(i-x>=1&&j-x>=1&&i+x<=n&&j+x<=m&&mp[i+x][j+x]=='#'&&mp[i+x][j-x]=='#'&&mp[i-x][j+x]=='#'&&mp[i-x][j-x]=='#'){
        x++;
    }
    return x-1;
}
void Atomatic_AC_machine(){
    cin>>n>>m;
    int t=min(n,m);
    vector<int> ans(t+1,0);
    for(int i=1;i<=n;i++){
        cin>>mp[i];
        mp[i]=" "+mp[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int res=check(i,j);
            if(res>=1)ans[res]++;
        }
    }
    for(int i=1;i<=min(n,m);i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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