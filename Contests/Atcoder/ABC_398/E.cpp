#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

// #define endl '\n'
#define all(x) x.begin(),x.end()

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
const i64 mod=1e9+7;
int col[N];
vector<int> e[N];
void dfs(int u,int fa){
    col[u]=col[fa]^1;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}
map<pii,int> vis;
set<pii> st;
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        if(u>v) swap(u,v);
        vis[{u,v}]=1;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(col[i]!=col[j]&&!vis[{i,j}]){
                st.insert({i,j});
            }
        }
    }
    int cnt= st.size();
    if(cnt%2==1){
        cout<<"First"<<endl;
        int op=0;
        while(1){
            if(op%2==0){
                auto [i,j]=*st.begin();
                cout<<i<<" "<<j<<endl;
                st.erase({i,j});
            }else{
                int i,j;cin>>i>>j;
                if(i==-1&&j==-1){
                    exit(0);
                }
                if(i>j) swap(i,j);
                st.erase({i,j});
            }
            op++;
        }
    }else{
        cout<<"Second"<<endl;
        int op=1;
        while(1){
            if(op%2==0){
                auto [i,j]=*st.begin();
                cout<<i<<" "<<j<<endl;
                st.erase({i,j});
            }else{
                int i,j;cin>>i>>j;
                if(i==-1&&j==-1){
                    exit(0);
                }
                if(i>j) swap(i,j);
                st.erase({i,j});
            }
            op++;
        }
    }

}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}