#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int maxn = 2e5+10;
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;

int vis[maxn],dis1[maxn],disn[maxn];
int chong[maxn];
vector <int> e[maxn];
void Atomatic_AC_machine(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++){
        dis1[i] = 0x3f3f3f3f;
        disn[i] = 0x3f3f3f3f;
    }
    for(int i = 1;i<=k;i++){
        int t;
        cin>>t;
        chong[t] = 1;

    }
    for(int i = 1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dis1[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //cout<<u<<endl;
        for(int v : e[u]){
            //cout<<v<<endl;
            if(vis[v]) continue;
            else {dis1[v] = dis1[u] + 1;
            vis[v] = 1;
            q.push(v);}
        }
    }
    memset(vis,0,sizeof(vis));
    disn[n] = 0;
    q.push(n);
    vis[n] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : e[u]){
            if(vis[v]) continue;
            else {disn[v] = disn[u] + 1;
            vis[v] = 1;
            q.push(v);}
        }
    }
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(chong[i]){
            sum +=disn[i];
        }
    }
    // for(int i = 1;i<=n;i++) cout<<dis1[i]<<" ";
    // cout<<endl;
    // for(int i = 1;i<=n;i++) cout<<disn[i]<<" ";
    // cout<<endl;
    int ansp = dis1[n],ansq = 1;
    for(int i = 1;i<=n;i++){
        if(chong[i]){
            int tp=dis1[i]*(k-1) + sum -disn[i];
        int tq = k-1;
        if(ansp*tq>ansq*tp){
            ansp = tp;
            ansq = tq;
            ansp /= __gcd(tp,tq);
            ansq /= __gcd(tp,tq);
        }
        }
        
    }
    cout<<ansp<<"/"<<ansq<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}