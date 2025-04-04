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
pii a[N];
set<int> vy,vy1;
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+m);
    vy.insert(n);
    vector<int> add;
    vector<int> del;
    for(int i=1;i<=m;i++){
        int y=a[i].second;
        if(vy.find(y+1)!=vy.end()||vy.find(y-1)!=vy.end()){
            if(y>=0&&y<=2*n) add.emplace_back(y);
        }else{
            if(vy.find(y)!=vy.end()) del.emplace_back(y);
        }
        if(i==m||a[i].first!=a[i+1].first){
            for(auto it:add){
                vy.insert(it);
            }
            for(auto it:del){
                vy.erase(it);
            }
            add.clear();
            del.clear();
        }
    }
    cout<<vy.size()<<endl;
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
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}