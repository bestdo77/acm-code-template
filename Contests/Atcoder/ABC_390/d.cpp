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
void print(vector<int> a){for(auto it:a) db(it);cendl}
int a[N];
int s[N];
int val,n;
unordered_set<int> st;
void dfs(int sz,int idx){//a[idx] could be placed in 1 ~ sz
    if(idx>n) return;
    for(int i=1;i<=sz;i++){
        val^=s[i];
        s[i]+=a[idx];
        val^=s[i];
        if(idx==n) st.insert(val);
        else if(i==sz) dfs(sz+1,idx+1);
        else dfs(sz,idx+1);
        val^=s[i];
        s[i]-=a[idx];
        val^=s[i];
    }
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<st.size()<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}