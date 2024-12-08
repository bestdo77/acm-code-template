#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf=0x3f3f3f3f3f3f3f3f;
int n,k;
const int N=5e6+10;
const int eps=2e6;
vector<int> a[N+10];
int t[N];
map<int,int> vis;
int cal(int x){
    if(k==0) return 0;
    int ans=0;
    int sum=0;
    for(auto it:a[x]){
        // cout<<"x"<<" "<<x<<" "<<it<<endl;
        sum+=it;
        ans=max(sum,ans);
        if(sum<0) sum=0;
    }
    return ans;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=n;i++){
        if(t[i]+k+eps>=0&&t[i]+k+eps<=N) a[t[i]+k+eps].push_back(1);
        a[t[i]+eps].push_back(-1);
        vis[t[i]]++;
    }
    int res=0;
    for(auto it:vis){
        int x=it.first;
        res=max({res,it.second+cal(x+eps),cal(x+k+eps)});
    }
    cout<<res<<endl;
    return 0;
}