#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
struct edge{
    int v,same;
};
vector<edge> e[32][N];
int ans[N];
int col[N];
vector<int> cur;
int cnt[2];
void dfs(int bit,int u,int c){
    cur.push_back(u);
    col[u]=c;
    cnt[c]++;
    for(auto [v,same]:e[bit][u]){
        if(col[v]!=-1){
            if(col[v]!=c^same){
                cout<<-1<<endl;
                exit(0);
            }
            continue;
        }
        dfs(bit,v,c^same);
    }
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        for(int j=0;j<32;j++){
            if(w&(1ll<<j)){
                e[j][u].push_back({v,1});
                e[j][v].push_back({u,1});
            }else{
                e[j][u].push_back({v,0});
                e[j][v].push_back({u,0});
            }
        }
    }

    for(int bit=0;bit<32;bit++){
        for(int i=1;i<=n;i++){
            col[i]=-1;
        }
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                cnt[0]=cnt[1]=0;
                cur.clear();
                dfs(bit,i,0);
                if(cnt[0]>cnt[1]){
                    for(auto u:cur){
                        ans[u]+=(col[u]==0) ? 0 : (1ll<<bit);
                    }
                }else{
                    for(auto u:cur){
                        ans[u]+=(col[u]==0) ? (1ll<<bit) : 0;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}