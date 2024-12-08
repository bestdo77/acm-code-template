#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pii out={inf,inf};
void Atomatic_AC_machine(){
    //每个方向都要有一个并查集，上下左右的父亲
    int n,m,k;cin>>n>>m>>k;
    pii fa[n+1][m+1][4];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++) fa[i][j][k]={i,j};
        }
    }
    queue<pii> q;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        for(int t=0;t<4;t++){
            int xx=x+dx[t];
            int yy=y+dy[t];
            // cout<<xx<<" "<<yy<<endl;
            if(fa[x][y][t]==make_pair(x,y)){//如果这个点没被炸过
                if(xx<1||xx>n||yy<1||yy>m) fa[x][y][t]=out;
                else fa[x][y][t]={xx,yy};
            }
            else{//如果被炸过了
                pii faa=fa[x][y][t];//寻找它的爹
                if(faa==out) continue;
                //它爹的四个方向都要修改
                for(int j=0;j<4;j++){
                    xx=faa.first+dx[j];
                    yy=faa.second+dy[j];//炸它的爹
                    // cout<<faa.first<<" "<<faa.second<<endl;
                    if(xx<1||xx>n||yy<1||yy>m) fa[faa.first][faa.second][j]=out; 
                    else fa[faa.first][faa.second][j]=fa[xx][yy][j];
                }
                //它只需要改一个方向的爹
                fa[x][y][t]=fa[faa.first][faa.second][t];
                // if(t==0) fa[faa.first][faa.second][1]=fa[x][y][1];
                // if(t==1) fa[faa.first][faa.second][0]=fa[x][y][0];
                // if(t==2) fa[faa.first][faa.second][3]=fa[x][y][3];
                // if(t==3) fa[faa.first][faa.second][2]=fa[x][y][2];
                // for(int i=1;i<=n;i++){
                //     for(int j=1;j<=m;j++){
                //         cout<<i<<" "<<j<<" "<<fa[i][j][0].first<<" "<<fa[i][j][0].second<<endl;
                //     }
                // }
                // cout<<endl;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(fa[i][j][0]!=make_pair(i,j)) ans++;
            while(fa[i][j][0]!=out&&fa[i][j][0]!=fa[fa[i][j][0].first][fa[i][j][0].second][0]){
                fa[i][j][0]=fa[fa[i][j][0].first][fa[i][j][0].second][0];
            }
        }
    }
    cout<<n*m-ans<<endl;
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