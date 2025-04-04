#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=2e3+10;
const int mod=998244353;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
int a[N1][N1];
int dp[N1][N1];
void Atomatic_AC_machine(){
    int h,w;cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char x;cin>>x;
            if(x=='-') a[i][j]=-1;
            else a[i][j]=1;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[h][w]=0;
    for(int i=h;i>=1;i--){
        for(int j=w;j>=1;j--){
            dp[i-1][j]=min(dp[i-1][j],-(dp[i][j]+a[i][j]));
            dp[i][j-1]=min(dp[i][j-1],-(dp[i][j]+a[i][j]));
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[1][1]<0){
        cout<<"Takahashi"<<endl;
    }else if(dp[1][1]==0){
        cout<<"Draw"<<endl;
    }else{
        cout<<"Aoki"<<endl;
    }
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