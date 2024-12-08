#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int mod=1e9+7;
const int element=2;
#pragma GCC optimize(3,"Ofast","inline")
int a[N];
unordered_map<int, int> mp;
vector<pii> v;
bool cmp(const pii &a, const pii &b){
    return a.first>b.first;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int sum=0;
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int maxx=0;
        unordered_map<int, int> mp;
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
            if(mp[a[i]]>=2){
                maxx=max(a[i], maxx);
            }
            a[i]=maxx;
            sum+=a[i];
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;
        mp.clear();
        maxx=0;
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
            if(mp[a[i]]>=2){
                maxx=max(a[i], maxx);
            }
            a[i]=maxx;
            // sum+=a[i];
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;
        mp.clear();
        for(int i=1;i<=n;i++){
            sum+=a[i]*(n-i+1);
        }
        cout<<sum<<endl;
    }
    return 0;
}