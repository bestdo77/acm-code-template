#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define tii tuple<int,int,int>
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
tii op[N];
int ans[N];
int a[N];
vector<int> lis;
void push(int x){
    int pos=lower_bound(lis.begin(),lis.end(),x)-lis.begin();
    if(pos==lis.size()){
        lis.emplace_back(x);
    }else{
        lis[pos]=min(lis[pos],x);   
    }
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=q;j++){
        int u,v,w=j;cin>>u>>v;
        op[j]={u,v,w};
    }
    sort(op+1,op+1+q);
    int p=1;
    for(int i=1;i<=q;i++){
        auto [r,x,id]=op[i];
        while(p<=r){
            push(a[p]);
            p++;
        }
        int pp=upper_bound(lis.begin(),lis.end(),x)-lis.begin();
        ans[id]=min(pp,(int)lis.size());
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
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