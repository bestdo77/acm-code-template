#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
char G[3][N];
char ans[3][4]={{0,0,0,0},{0,'.','.','.'},{0,'x','.','x'}};
char ans1[3][4]={{0,0,0,0},{0,'x','.','x'},{0,'.','.','.'}};
bool check(int p){
    bool flag1=1,flag2=1;
    for(int i=1;i<=2;i++){
        for(int j=p;j<=p+2;j++){
            if(G[i][j]!=ans[i][j-p+1]) flag1=0;
            if(G[i][j]!=ans1[i][j-p+1]) flag2=0;
            if(!flag1&&!flag2) return false;
        }
    }
    return true;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            cin>>G[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n-2;i++){
        if(check(i)) cnt++;
    }
    cout<<cnt<<endl;
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