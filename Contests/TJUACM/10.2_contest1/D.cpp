#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e4+10;
const int N1=1e3+10;
const int mod=1e9+7;
int vis[N],fa[N],dep[N];
vector<int> e[N];
int cnt;
struct node{
    int x,y;
}P[N];
priority_queue <pii> q;
void dfs1(int x,int father){
    int cnt = 0;
    fa[x] = father;
    vis[x] = 1;
    dep[x] = dep[father] + 1;
    for(int y : e[x]){
        if(y == father) continue;
        else if(!vis[y]){dfs1(y,x);cnt++;}
    }
    if(!cnt) q.push(make_pair(dep[x],x));
}
int mp[110][110];

int dx[8]={2,2,1,1,-2,-2,-1,-1};
int dy[8]={1,-1,-2,2,1,-1,-2,2};
void Atomatic_AC_machine(){
    int n;
    cin >>n;
    char k;
    cin>>k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            char t;
            cin>>t;
            if(t != '.'){ mp[i][j] = ++cnt;P[cnt].x=i;P[cnt].y=j;}
        }
    }
    if(k =='R'){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mp[i][j]){
                    for(int p = 1;p<=n;p++){
                        if(p==j) continue;
                        if(mp[i][p]) {
                            e[mp[i][p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i][p]);
                        }
                    }
                    for(int p = 1;p<=n;p++){
                        if(p==i) continue;
                        if(mp[p][j]) {
                            e[mp[p][j]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[p][j]);
                        }
                    }
                }
            }
        }
    }
    else if(k =='Q'){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mp[i][j]){
                    for(int p = 1;p<=n;p++){
                        if(p==j) continue;
                        if(mp[i][p]) {
                            e[mp[i][p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i][p]);
                        }
                    }
                    for(int p = 1;p<=n;p++){
                        if(p==i) continue;
                        if(mp[p][j]) {
                            e[mp[p][j]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[p][j]);
                        }
                    }
                    for(int p = -100;p<=100;p++){
                        if(i+p>=1&&i+p<=n&&j+p>=1&&j+p<=n&&mp[i+p][j+p]){
                            e[mp[i+p][j+p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i+p][j+p]);
                        }
                    }
                    for(int p = -100;p<=100;p++){
                        if(i+p>=1&&i+p<=n&&j-p>=1&&j-p<=n&&mp[i+p][j-p]){
                            e[mp[i+p][j-p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i+p][j-p]);
                        }
                    }
                }
            }
        }
    }
    else if(k=='B'){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mp[i][j]){
                    for(int p = -100;p<=100;p++){
                        if(i+p>=1&&i+p<=n&&j+p>=1&&j+p<=n&&mp[i+p][j+p]){
                            e[mp[i+p][j+p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i+p][j+p]);
                        }
                    }
                    for(int p = -100;p<=100;p++){
                        if(i+p>=1&&i+p<=n&&j-p>=1&&j-p<=n&&mp[i+p][j-p]){
                            e[mp[i+p][j-p]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[i+p][j-p]);
                        }
                    }
                }
            }
        }
    }
    else if(k=='N'){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mp[i][j]){
                    for(int p =0;p<8;p++){
                        int x=i+dx[p];
                        int y=j+dy[p];
                        if(x>=1&&x<=n&&y>=1&&y<=n&&mp[x][y]){
                            e[mp[x][y]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[x][y]);
                        }
                    }
                }
            }
        }
    }
    else{
        int ddx[8] = {-1,-1,-1,0,0,1,1,1};
        int ddy[8] = {-1,0,1,-1,1,-1,0,1};
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(mp[i][j]){
                    for(int p =0;p<8;p++){
                        int x=i+ddx[p];
                        int y=j+ddy[p];
                        if(x>=1&&x<=n&&y>=1&&y<=n&&mp[x][y]){
                            e[mp[x][y]].push_back(mp[i][j]);
                            e[mp[i][j]].push_back(mp[x][y]);
                        }
                    }
                }
            }
        }
    }
    dfs1(1,0);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(mp[i][j]){
                if(!vis[mp[i][j]]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        if(!vis[x]) continue;
        if(x == 1) break;
        vis[x] = 0;
        int father =fa[x];
        cout<<P[x].x<<" "<<P[x].y<<" "<<P[father].x<<" "<<P[father].y<<endl;
        q.push(make_pair(dep[father],father));
    }
}   
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}