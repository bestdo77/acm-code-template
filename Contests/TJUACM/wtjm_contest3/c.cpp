#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
//#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=1010;

vector <int> e[N];
int dfn[N],low[N],dfncnt=0;
int vis[N];
int cut[N],res=0; //ans[i]=1 -> 点i是割点
int sta[N],top,dcccnt;
int n,m;
int ed[N][N];
vector <int> dcc[N];
int root;
int ans[N];
struct Dsu{
    int f[2*N],color[N];
    void init(int n){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    }
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }

    void join(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy){
            f[fy]=fx;
        }
    }
};
Dsu dsu;
bool has_odd_cycle(int p) {
    dsu.init(2*n);
    for(int j=0;j<dcc[p].size();j++){
        int u=dcc[p][j];
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i];
            if(u==v) continue;
            if (dsu.find(u) == dsu.find(v)) {
                    return true; // 存在奇环
            }else{
                dsu.join(u,v+n);
                dsu.join(v,u+n);
            }
        }
    }
    return false;
}
void Tarjan(int u,int fa){
    vis[u]=1;
    low[u]=dfn[u]=++dfncnt;sta[++top]=u;
    if (u==root&&e[u].size()==0){
        dcc[++dcccnt].push_back(u);
        return;
    }
    int ccnt=0;
    int len=e[u].size();
    for (int i=0;i<len;i++){
        int v=e[u][i];
        if(v==fa)continue;
        if(!vis[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]){
                if (++ccnt>1||u!=root)cut[u]=1;
                dcccnt++;
                do dcc[dcccnt].push_back(sta[top--]);
                while (sta[top+1]!=v);
                dcc[dcccnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}


signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    while(cin >>n>>m&&n+m!=0){
        for(int i=1;i<=n;i++){
            ans[i]=dfn[i]=low[i]=vis[i]=cut[i]=sta[i]=0;
            e[i].clear();
        }
        for(int i=1;i<=dcccnt;i++){
            dcc[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ed[i][j]=0;
            }
        }
        res=top=dcccnt=dfncnt=0;
        for (int i=0;i<m;i++){
            int u,v;
            cin >>u>>v;
            ed[u][v]=ed[v][u]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) continue;
                if(ed[i][j]==0){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        dsu.init(n);
        for (int i=1;i<=n;i++){
            if(!vis[i]){
                root=i;Tarjan(i,i);
            }
        }
        for(int i=1;i<=dcccnt;i++){
            if(has_odd_cycle(i)){
                for(int j=0;j<dcc[i].size();j++){
                    ans[dcc[i][j]]=1;
                }
            }
        }
        cout<<n-accumulate(ans+1,ans+1+n,0)<<endl;
    }
}