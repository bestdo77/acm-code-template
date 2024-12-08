#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
//#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=1050;

vector <int> e[N];
int w[N][N];

int low[N],dfn[N],dfncnt=0;
int ans[N];int res=inf;
int father[N],vis[N];//ans[i]==1 -> 从i到father[i]存在一个割边。

void Tarjan(int u,int fa){
    vis[u]=1;
    father[u]=fa;
    low[u]=dfn[u]=++dfncnt;
    int len=e[u].size();
    for (int i=0;i<len;i++){
        int v=e[u][i];
        if(!vis[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans[v]=1;
            }
        }
        else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
}


signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    while (cin >>n>>m){
        //cout <<n<<endl;
        res=inf;
        dfncnt=0;
        if(n==0)break;
        dfncnt=0;
        for (int i=0;i<=n;i++){
            e[i].clear();
            dfn[i]=0;
            low[i]=0;
            ans[i]=0;
            father[i]=0;
            vis[i]=0;
        }
        memset(w,0,sizeof w);
        for (int i=0;i<m;i++){
            int u,v,ww;
            cin >>u>>v>>ww;
            e[u].push_back(v);
            e[v].push_back(u);
            if(!w[u][v])w[u][v]=w[v][u]=ww;
            else w[u][v]=w[v][u]=inf;

        }
        Tarjan(1,-1);
        for (int i=1;i<=n;i++){
            if(ans[i]){
                res=min(res,w[i][father[i]]);
            }
        }
        if(res==0)res=1;
        for (int i=1;i<=n;i++){
            if(!vis[i])res=0;
        }
        if(res==inf){
            cout <<-1<<endl;
        }else cout <<res<<endl;
    }
}