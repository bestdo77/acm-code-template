#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
const int infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());




const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
vector<int> e[N];
vector<int> bylarge[N];
void Atomatic_AC_machine(){
    int n,c;cin>>n>>c;
    vector<int> large(c+1,0),ans(c+1,0),a(n+1,0),largenum(c+1,0);
    for(int i=1;i<=c;i++){
        e[i].clear();
        bylarge[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int m;cin>>m;
    int deg=sqrt(m);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        if(u!=v) e[v].push_back(u);
    }
    for(int i=1;i<=c;i++){
        if(e[i].size()>deg){
            large[i]=1;
            for(auto v:e[i]){
                bylarge[v].push_back(i);
            }
        }
    }   
    if(large[a[1]]) largenum[a[1]]=1;
    else{
        for(auto v:e[a[1]]){
            ans[v]++;
            ans[v]%=mod;
        }
    }
    for(int i=2;i<=n;i++){
        int tmp=ans[a[i]];
        for(auto u:bylarge[a[i]]){
            tmp+=largenum[u];
            tmp%=mod;
        }
        if(i==n){
            cout<<tmp<<endl;
        }
        if(!large[a[i]]){
            for(auto v:e[a[i]]){
                ans[v]+=tmp;
                ans[v]%=mod;
            }
        }else{
            largenum[a[i]]+=tmp;
            largenum[a[i]]%=mod;
        }
    }
}   
signed main(){
//     int size(256<<20);  // 256M
//   __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}