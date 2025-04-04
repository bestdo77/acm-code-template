#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int cnt=0;
struct edge{
    int v;
    char w;
};
vector<edge> e[N];
char s[N];
int p;
bool check(){
    int l=0,r=p-1;
    while(l<=r){
        if(s[l]!=s[r]) return 0;
        l++;r--;
    }
    return 1;
}
int ans[N1][N1];
int d[N1][N1];
int n;
void dfs(int st,int u){
    if(cnt>=2e8) return;
    cnt++;
    if(p>3*d[st][u]) return;
    if(check()){
        ans[st][u]=min(ans[st][u],p);
    }
    for(auto [v,w]:e[u]){
        s[p++]=w;
        dfs(st,v);
        p--;
    }
}
void Atomatic_AC_machine(){
    cin>>n;
    // n=100;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=(i==j?0:inf);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;
            cin>>x;
            if(x!='-'){
                e[i].push_back(edge{j,x});
                d[i][j]=1;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        p=0;
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]!=inf) cout<<ans[i][j]<<" ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // auto begin = std::chrono::high_resolution_clock::now();
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}