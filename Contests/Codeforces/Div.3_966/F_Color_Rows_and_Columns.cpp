#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[5100000];
const int N=2e3+10;
int w[N][N],v[N][N],dp[(int)1e7],s[N],n,c,k;//dp表示体积为x的背包能装的最大价值
void solve(){
    cin>>n>>k;
    c=0;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        s[i]=x+y-1;
        c+=(x+y);
        int len=min(x,y);
        int cnt=1;
        w[i][s[i]+1]=v[i][s[i]+1]=0;
        for(int j=s[i];j>=1;j--){
            if(s[i]-j<=max(x,y)-min(x,y)) v[i][j]=len+v[i][j+1];
            else if(cnt%2){
                len--;
                v[i][j]+=v[i][j+1]+len;
                cnt++;
            }else{
                v[i][j]+=v[i][j+1]+len;
                cnt++;
            }
            w[i][j]=w[i][j+1]+1;
            if(j==1) w[i][j]++;
        }
    }
    for(int i=1;i<=200;i++) dp[i]=inf;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=s[i];j++){
    //         cout<<w[i][j]<<" "<<v[i][j]<<"|";
    //     }cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=200;j>=0;j--){
            for(int k=0;k<=s[i];k++){//k=0代表不取
                if(j>=w[i][k]){
                    dp[j]=min(dp[j],v[i][k]+dp[j-w[i][k]]);
                }
            }
        }
    }
    // cout<<c<<endl;
    // for(int i=1;i<=c;i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=200;j++){
            v[i][j]=w[i][j]=0;
        }
    }
    bool flag=1;
    int mn=inf;
    for(int i=k;i<=200;i++){
        mn=min(mn,dp[i]);
    }
    if(mn==inf) cout<<-1<<endl;
    else cout<<mn<<endl;
    return;
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