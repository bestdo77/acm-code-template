#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn = 2e5+10;
vector <int> e[maxn];
int a[maxn];
int vis[maxn];
vector <int> ans[maxn];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >>n>>m>>k;
    for (int i=1;i<=k;i++){
        int tem;cin >>tem;
        a[tem]=1;
    }
    for (int i=1;i<=m;i++){
        int u,v;
        cin >>u>>v;
        if (a[u]&&a[v])continue;
        else if (a[u])e[v].push_back(u);
        else if (a[v])e[u].push_back(v);
        else {
            e[v].push_back(u);
            e[u].push_back(v);
        }
    }
    int st=0;
    for (int i=1;i<=n;i++){
        if (!a[i]){
            st=i;
            break;
        }
    }
    if (st==0){
        cout <<"No"<<endl;
        return 0;
    }
    queue <int> q;
    q.push(st);
    vis[st]=st;
    while (!q.empty()){
        int tem=q.front();
        q.pop();
        for (auto it:e[tem]){
            if (!vis[it]){
                q.push(it);
                vis[it]=tem;
                ans[tem].push_back(it);
            }
        }
    }
    int flag=1;
    int res=0;
    for (int i=1;i<=n;i++){
        if (!vis[i])flag=0;
        if (!ans[i].empty())res++;
    }
    if (flag){
        cout <<"Yes"<<endl;
        cout <<res<<endl;
        queue <int> ansq;
        ansq.push(st);
        while (!ansq.empty()){
            int tem=ansq.front();
          //  cout <<tem<<endl;
            ansq.pop();
            if (ans[tem].empty())continue;
            cout <<tem<<" ";
            cout <<ans[tem].size()<<" ";
            for (auto it:ans[tem]){
                cout <<it<<" ";
                ansq.push(it);
            }
            cout <<endl;
        }
    }else{
        cout <<"No"<<endl;
    }
}