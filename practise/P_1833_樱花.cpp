#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e7+10;
const int mod=1e9+7;
const int element=3;
int a[N];
// vector<array<int,element>> v;
int dp[N],v[N],w[N],p[N],W[N],V[N];
void solve(){
    int h1=0,h2=0,min1=0,min2=0,n;
    scanf("%d:%d %d:%d %d",&h1,&min1,&h2,&min2,&n);
    int c=h2*60+min2-h1*60-min1;
    for(int i=0;i<=c;i++) dp[i]=0;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i]>>p[i];
        if(p[i]==0) p[i]=c/w[i]+1;
    }
    int num=0;
    for(int i=1;i<=n;i++){
        int tmp=p[i];
        for(int j=1;j<=tmp;tmp-=j,j<<=1) ++num,W[num]=j*w[i],V[num]=j*v[i];
        if(tmp) ++num,W[num]=tmp*w[i],V[num]=tmp*v[i];
    }
    for(int i=1;i<=num;i++){
        for(int j=c;j>=W[i];j--){
            dp[j]=max(dp[j],dp[j-W[i]]+V[i]);
        }
    }
    cout<<dp[c]<<endl;
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; 
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}