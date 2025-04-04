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

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a);
vector<int> generate_data(int n, int range);
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    vector<int> a(2*n+1,0);
    vector<int> vis(2*n+1,0);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[x]++;
    }
    int re=0;
    int ans=0;
    for(int i=1;i<=k-1;i++){
        if(!vis[i]&&!vis[k-i]){
            if(2*i==k){
                ans+=a[i]/2;
                vis[i]=1;
                db(i<<" "<<ans);
                cendl
            }else{
                re+=abs(a[i]-a[k-i]);
                ans+=min(a[i],a[k-i]);
                vis[i]=vis[k-i]=1;
                db(i<<" "<<ans);
                cendl
            }
        }   
    }
    cout<<ans<<endl;
}   
signed main(){
    
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    int i=0;
    while(t--){
        i++;cerr << "Case #" << i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
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
    for(auto it:a) cerr<<it<<" ";
    cerr<<endl;
}