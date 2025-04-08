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
map<pii,int> vis;
vector<int> e[N];
int din[N];
int vis1[26],vis2[26];
void dfs(int u){
    if(vis2[u]) return;
    vis2[u]=1;
    for(auto v:e[u]){
        dfs(v);
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        int u=s[i]-'a',v=t[i]-'a';
        if(!vis.count(pii{u,v})){
            vis1[u]=vis1[v]=1;
            vis[{u,v}]=1;
            e[u].push_back(v);
            din[v]++;
            ans++;
            if(u==v){
                vis2[u]=1;
                ans--;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(e[i].size()>1){
            cout<<-1<<endl;
            return;
        }
    }
    queue<int> q;
    for(int i=0;i<26;i++){
        if(!din[i]) q.push(i);
    }
    while(q.size()){
        int u=q.front();
        vis2[u]=1;
        q.pop();
        for(auto v:e[u]){
            --din[v];
            if(!din[v]) q.push(v);
        }
    }
    int re=26-accumulate(vis1,vis1+26,0);//可以借来拆环的字母
    int cnt=0;
    // for(int i=0;i<26;i++){
    //     if(vis1[i]&&!vis2[i]){
    //         db(char('a'+i))
    //     }
    // }
    // cendl
    for(int i=0;i<26;i++){
        if(vis1[i]&&!vis2[i]){//成环了
            dfs(i);
            cnt++;
        }
    }
    // db(ans<<" "<<cnt<<" "<<re)
    // cendl
    if(cnt>re){
        cout<<-1<<endl;
    }else{
        cout<<ans+cnt<<endl;
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