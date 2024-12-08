#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e7+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int pre[N],pre2[N];
int p[N];
map<int,int> maps;
void solve(){
    int n,m;cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            maps[x]++;
        }
        int ans=0;
        int p=0,p1=0;
        for(auto it:maps){
            if(it.second==1) ans++;
            if(it.second==2) p=1;
            if(it.second>2) p1=1;
        }
        if(p) cout<<ans+2<<endl;
        else if(p1) cout<<ans+1<<endl;
        else cout<<ans<<endl;
    }else{
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            p[i]=x;
            a[x]++;
            a[x+m]--;
        }
        for(int i=1;i<=2e7;i++){
            a[i]+=a[i-1];
        }
        int ans=0;
        for(int i=1;i<=2e7;i++){
            pre[i]=pre[i-1];
            pre2[i]=pre2[i-1];
            if(a[i]==1) pre[i]++,ans++;
            if(a[i]==2) pre2[i]++;
        }
        int ans1=ans;
        // for(int i=1;i<=20;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;
        for(int i=1;i<=n;i++){
            //右区间x+m-1,左区间x
            int x=p[i];
            ans1=max(m+pre2[x+m-1]-pre2[x-1]-(pre[x+m-1]-pre[x-1])+ans,ans1);
        }
        cout<<ans1<<endl;
    }
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