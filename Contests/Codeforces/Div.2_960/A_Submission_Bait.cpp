#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
vector<int> a;
vector<array<int,element>> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int, int> mp;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            mp[x]++;
        }
        int maxx=0;
        bool flag=0;
        for(auto i:mp){
            if(i.second%2==1) flag=1;
            // cout<<i.first<<" "<<i.second<<endl;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        mp.clear();
    }
}