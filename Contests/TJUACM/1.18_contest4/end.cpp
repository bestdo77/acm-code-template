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
int a[N1][N1];
int ans[N1][N1];
int pre[N1][N1];
int n,k;
bool check(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]>x) ans[i][j]=1;
            else ans[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+ans[i][j];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            int query=pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k];
            if(query<k*k/2+1) return 1;
        }
    }
    return 0;
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int l=-1,r=1e9+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
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