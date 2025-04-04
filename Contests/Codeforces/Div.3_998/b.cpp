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
vector<int> a[N];
bool cmp(vector<int> a1,vector<int> a2){
    return a1[0]<a2[0];
}
bool cmp1(int x,int y){
    return a[x][0]<a[y][0];
}
int b[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    for(int i=1;i<=n;i++){
        b[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;cin>>x;
            a[i].push_back(x);
        }
        sort(a[i].begin(),a[i].end());
    }
    sort(b+1,b+1+n,cmp1);
    sort(a+1,a+1+n,cmp);
    int idx=0;
    for(int i=1;i<=n;i++){
        print(a[i]);
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j]==idx){
                idx++;
            }else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
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