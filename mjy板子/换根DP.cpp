#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=2000050;


vector <int> e[N]; int n;
int depth[N],sum[N],ans[N];

//第一次DFS处理子树点数，深度等信息
void dfs1(int u,int fa){
    depth[u]=depth[fa]+1;
    sum[u]=1;
    for (int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v!=fa){
            dfs1(v,u);
            sum[u]+=sum[v];//<-自下而上
        }
    }
}

//第二次DFS“换根”
void dfs2(int u,int fa){
    for (int i=0;i<e[u].size();i++){
        
        int v=e[u][i];
        if(v!=fa){
            ans[v]=ans[u]-sum[v]+(n-sum[v]);//<-自上而下
            dfs2(v,u);
        }
    }
}


signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   
    cin >>n;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1,1);

    for (int i=1;i<=n;i++)ans[1]+=depth[i];
    dfs2(1,1);

    int res=-1,resp=-1;
    for (int i=1;i<=n;i++){
        if(ans[i]>res){
            res=ans[i];
            resp=i;
        }
    }
    cout <<resp<<endl;
}