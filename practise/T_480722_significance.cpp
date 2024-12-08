#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
vector<int> v[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        for(int j=1;j<=t;j++){
            int x;cin>>x;
            v[i].push_back(x);
        }
    }
    set<int> s;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(auto it:v[i]){
            s.insert(it);
            for(auto it2:v[it]){
               if(it2!=i) s.insert(it2);
            }
        }
        cout<<s.size()<<" ";
        s.clear();
    }
    cout<<endl;
    return 0;
}