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
map<int,int> vis;
void Atomatic_AC_machine(){
    int n;cin>>n;
    vis.clear();
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        vis[x]++;
    }
    bool flag=0;
    for(auto [x,cnt]:vis){
        if((vis[x]>=4)){
            flag=1;
            break;
        }else if(vis[x]>=2&&(vis[x-1]>=2||vis[x+1]>=2)){
            flag=1;
            break;
        }else if(vis[x-1]>=2&&vis[x+1]>=2&&vis[x]){
            flag=1;
            break;
        }
    }
    cout<<(flag?"Yes":"No")<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }   
    return 0;
}