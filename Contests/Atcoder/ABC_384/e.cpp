#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int cell[N1][N1];
int vis[N1][N1];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct node{
    int x,y,val;
    bool operator>(const node& other) const{
        return val>other.val;
    }
};
int X,sum;
bool check(int x){
    return sum>X*x;
}
priority_queue<node,vector<node>,greater<node>> pq; 
void Atomatic_AC_machine(){
    long long n,m,tt;cin>>n>>m>>tt;
    X=tt;
    long long p,q;cin>>p>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            long long x;cin>>x;
            cell[i][j]=x;
        }
    }
    pq.push(node{p,q,cell[p][q]});
    while(pq.size()){
        node tmp=pq.top();
        if(!check(tmp.val)&&sum!=0) break; 
        // cout<<tmp.val<<endl;
        pq.pop();
        int x=tmp.x;
        int y=tmp.y;
        if(vis[x][y]) continue;
        sum+=tmp.val;
        vis[x][y]=1;
        int minval=inf;
        for(int i=0;i<4;i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty]) continue;
            pq.push(node{tx,ty,cell[tx][ty]});
        }
    }
    long long anss=sum;
    cout<<anss<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}