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
int a[N];
int n,k;
int mn=inf;
int mnr=0;
bool check(int k){
    int cnt=0;
    int mh=inf;
    for(int i=n-k-1;i>=1;i--){
        if(a[i]<=mh/2){
            cnt++;
            mh=a[i];
        }
    }
    cout<<k<<" "<<cnt<<endl;
    if(cnt==mn){
        return 1;
    }else{
        return 0;
    }
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    check(k);
    sort(a+1,a+1+n);
    int l=-1,r=k+1;
    // cout<<check(4)<<endl;
    // cout<<mn<<endl;
    while(l+1<r){
        int mid=l+r>>1;
        cout<<mid<<endl;
        if(check(mid)){
            r=mid;
            mnr=min(mnr,r);
        }else{
            l=mid;
        }
    }
    cout<<mn<<" "<<mnr<<endl;
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