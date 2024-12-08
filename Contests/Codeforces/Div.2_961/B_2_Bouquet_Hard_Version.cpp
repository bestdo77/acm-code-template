#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<array<int,element>> v;
void solve(){
    int n,m;cin>>n>>m;
    map<int, int> mp;
    // map<int,int>::iterator it = mp.begin();
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[a[i]]=x;
    }
    int last=0,ans=0;
    for(auto it:mp){
        if(it.first-last<=1&&last!=0&&it.first!=0){
            int v=last,ans1=0,c2=it.second,c1=mp[last];
            int tmp=v*min(c1,m/v);
            c1=min(c1,m/v);
            ans1+=tmp;
            ans1+=(v+1)*min(c2,(m-tmp)/(v+1));
            c2=min(c2,(m-tmp)/(v+1));
            ans1+=min(c1,it.second-c2);
            ans1=min(ans1,m);
            ans=max(ans,ans1);
        }else{
            int ans1=it.first;
            ans1=it.first*min(it.second,m/it.first);
            ans=max(ans,ans1);
        }
        last=it.first;
    }
    cout<<ans<<endl;
    // int ans=0;
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