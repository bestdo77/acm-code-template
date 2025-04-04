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
vector<int> e[N];
int deg[N];
int ans[N];
int ans1[N];
int s;
void dfs(int u,int fa){
    vector<int> tmp;
    for(auto v:e[u]){
        if(v!=fa) dfs(v,u);
        if(deg[v]>=4&&v!=fa) tmp.push_back(ans1[v]);
        else tmp.push_back(1);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    if(deg[u]>=4) ans[u]=tmp[0]+tmp[1]+tmp[2]+tmp[3],ans1[u]=tmp[0]+tmp[1]+tmp[2]+1;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        ans[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]>=4){
            s=i;
            break;
        }
    }
    if(s==0){
        cout<<-1<<endl;
        return;
    }else{
        dfs(s,0);
        int mx=0;
        for(int i=1;i<=n;i++){
            db(ans[i])
            if(deg[i]>=4) mx=max(mx,ans[i]);
        }
        cendl
        cout<<mx+1<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}