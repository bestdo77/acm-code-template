#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
struct edge{
    int v,w;
};
vector<edge> e[N];
int one[N][61];//第i位的前缀1数量
int zero[N][61];
int dxor[N];
void dfs(int u,int fa,int d){
    dxor[u]=d;
    for(auto ed:e[u]){
        int v=ed.v;
        int w=ed.w;
        if(v==fa) continue;
        d^=w;
        dfs(v,u,d);
        d^=w;
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u].push_back(edge{v,w});
        e[v].push_back(edge{u,w});
    }
    dfs(1,0,0);
    // for(int i=1;i<=n;i++){
    //     cout<<dxor[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<61;j++){
            one[i][j]=one[i-1][j];
            zero[i][j]=zero[i-1][j];
            if(dxor[i]&(1ll<<j)){
                one[i][j]++;   
            }else{
                zero[i][j]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<61;j++){
            if(dxor[i]&(1ll<<j)){//这一位是1，找0
                ans=(ans+((1ll<<j)%mod*(zero[n][j]-zero[i][j])%mod)%mod)%mod;
            }else{
                ans=(ans+((1ll<<j)%mod*(one[n][j]-one[i][j])%mod)%mod)%mod;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}