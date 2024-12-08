#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],c[N];
vector<int> b[N];
int nowsum,maxsum;
void dfs(int i,int x){
    if(x>=a[i]){
        maxsum=max(maxsum,nowsum);
        return;
    }
    if(b[i][x]+nowsum<=c[i]/2){
        nowsum+=b[i][x];
        dfs(i,x+1);
        nowsum-=b[i][x];
    }
    dfs(i,x+1);
}
void solve(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=a[i];j++){
            int x;cin>>x;
            b[i].push_back(x);
            c[i]+=x;
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        nowsum=maxsum=0;
        dfs(i,0);
        ans+=c[i]-maxsum;
    }
    cout<<ans<<endl;
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