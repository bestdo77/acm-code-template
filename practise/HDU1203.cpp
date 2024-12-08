#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=1e4+10;
int a[N];
int w[N];
double dp[N],v[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n;
    while(cin>>c>>n&&(n+c!=0)){
     	for(int i=1;i<=n;i++){
           double x,y;cin>>x>>y;
           w[i]=x;
           v[i]=1-y;
           if(c==0&&v[i]==1){
               cout<<"100%"<<endl;
               return 0;
           }
        }
        for(int i=0;i<=c;i++) dp[i]=1;
        for(int i=1;i<=n;i++){
            for(int j=c;j>=w[i];j--){
                dp[j]=min(dp[j-w[i]]*v[i],dp[j]);
            }
        }
        printf("%.1lf%\n",(1-dp[c])*100);   
    }
    return 0;
}