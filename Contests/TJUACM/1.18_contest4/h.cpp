#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define debug(x) cout<<x<<endl;
void print(vector<int> a);
vector<int> generate_data(int n, int range);
set<int> st;
int a[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    vector<int> ans;
    ans.push_back(0);
    // k--;
    while(k--){
        int mn=inf;
        for(int i=max(0ll,(int)ans.size()-10);i<ans.size();i++){
            int mx=ans.back();
            for(int j=1;j<=n;j++){
                int to=*upper_bound(ans.begin(),ans.end(),mx-a[j]);
                if(a[j]+to>mx) mn=min(mn,a[j]+to);
            }
        }
        ans.push_back(mn);
        // cout<<mn<<endl;
    }
    cout<<ans.back()<<endl;
}   
signed main(){
    
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        //cout << "Case #" << i << ": ";
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
vector<int> generate_data(int n, int range) {
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = 1 + RNG() % range; // 生成 1 到 range 之间的随机数
    }
    return data;
}
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}