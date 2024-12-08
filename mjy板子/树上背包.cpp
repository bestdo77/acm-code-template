#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;


int fa[N],a[N];
vector <int> e[N];
int n,m;

int dp[N][N];//dp[i][j]代表以i为根，选取j件物品的最大值。
//可以增加一个点0，使森林中所有根节点都连向0，dp[0][m]就是最终结果。

void dfs(int r){
    dp[r][0]=-inf;
    dp[0][0]=0;
    for (int i=1;i<=m;i++)dp[r][i]=a[r];

    for (int i=0;i<e[r].size();i++){
        int v=e[r][i];
        dfs(e[r][i]);

        //注意循环顺序。
        for (int j=m;j>=1;j--){
            for (int k=1;k<=j;k++){
                dp[r][j]=max(dp[r][j],dp[r][j-k]+dp[v][k]);
            }
        }

    }
}

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>fa[i]>>a[i];
        e[fa[i]].push_back(i);
    }
    dfs(0);
    cout <<dp[0][m]<<endl;
}