#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int n,k,q;cin>>n>>k>>q;
    multiset<int> set;
    map<int,int> mp;
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        set.insert(0);
    }
    for(int i=1;i<k;i++){
        set.erase(set.find(mp[a[i]-i]));
        mp[a[i]-i]++;
        set.insert(mp[a[i]-i]);
    }
    for(int i=k;i<=n;i++){
        set.erase(set.find(mp[a[i]-i]));
        mp[a[i]-i]++;
        set.insert(mp[a[i]-i]);
        int p=i-k+1;
        ans[p]=k-*set.rbegin();
        set.erase(set.find(mp[a[p]-p]));
        mp[a[p]-p]--;
        set.insert(mp[a[p]-p]);
    }   
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        cout<<ans[l]<<endl;
    }
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