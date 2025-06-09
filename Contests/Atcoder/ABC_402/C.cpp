#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
vector<int> hav[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    vector<int> ans(n+10,0),lst(n+1,0);
    for(int i=1;i<=m;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x;cin>>x;
            hav[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        lst[x]=i;
    }
    for(int i=1;i<=m;i++){
        int mx=0;
        for(auto v:hav[i]){
            mx=max(mx,lst[v]);
        }
        ans[mx]++;
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}