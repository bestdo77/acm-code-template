#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[1010][1010];
int pre[1010][1010];
pii a[N];
void print(){
    for(int j=0;j<=20;j++){
        for(int k=0;k<=20;k++){
            cout<<dp[j][k]<<" ";
        }cout<<endl;
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].second;
    }
    // cout<<sum<<endl;
    if(sum%3){
        cout<<-1<<endl;
        return;
    }
    for(int j=0;j<=1000;j++){
        for(int k=0;k<=1000;k++){
            dp[j][k]=pre[j][k]=inf;
        }
    }
    dp[0][0]=pre[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1000;j>=0;j--){
            for(int k=1000;k>=0;k--){
                pre[j][k]=dp[j][k];
            }
        }
        for(int j=1000;j>=0;j--){
            for(int k=1000;k>=0;k--){
                dp[j][k]=inf;
            }
        }

        for(int j=1000;j>=0;j--){
            for(int k=1000;k>=0;k--){
                if(a[i].first==1){
                    if(j+a[i].second<=1000) dp[j+a[i].second][k]=min(dp[j+a[i].second][k],pre[j][k]);
                    if(k+a[i].second<=1000) dp[j][k+a[i].second]=min(dp[j][k+a[i].second],pre[j][k]+1);
                    dp[j][k]=min(dp[j][k],pre[j][k]+1);
                }else if(a[i].first==2){ 
                    if(j+a[i].second<=1000) dp[j+a[i].second][k]=min(dp[j+a[i].second][k],pre[j][k]+1);
                    if(k+a[i].second<=1000) dp[j][k+a[i].second]=min(dp[j][k+a[i].second],pre[j][k]);
                    dp[j][k]=min(dp[j][k],pre[j][k]+1);
                }else{
                    if(j+a[i].second<=1000) dp[j+a[i].second][k]=min(dp[j+a[i].second][k],pre[j][k]+1);
                    if(k+a[i].second<=1000) dp[j][k+a[i].second]=min(dp[j][k+a[i].second],pre[j][k]+1);
                    dp[j][k]=min(dp[j][k],pre[j][k]);
                }
            }
        }
        // print();  
    }
    if(dp[sum/3][sum/3]!=inf) cout<<dp[sum/3][sum/3]<<endl;
    else cout<<-1<<endl;
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