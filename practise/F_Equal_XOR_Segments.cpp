#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    vector<int> a(n+1);
    vector<int> pre(n+1);
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
    mp[0].push_back(0);
    for(int i=1;i<=n;i++){
        mp[pre[i]].push_back(i);
    }
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        if(pre[r]==pre[l-1]) cout<<"YES"<<endl;
        else{
            int ll=*--lower_bound(mp[pre[l-1]].begin(),mp[pre[l-1]].end(),r);//这里找最大的
            int rr=*lower_bound(mp[pre[r]].begin(),mp[pre[r]].end(),l);
            // cout<<ll<<" "<<rr<<endl;
            if(ll>rr) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}