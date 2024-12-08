#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1005;
int n,m,q;
int tag=0,cnt=0;//tag标记第几次询问
char a[N][N];
int id[N][N][4];//标记第几次询问
int used[N][N][4];//单次搜索中是否镜子是否被反光过
int memory[N][N][4];//记忆化搜索
typedef pair<int,int> PII;
vector<array<int,3>> path;//记录成环的路径,类似一个struct存在了一个可以动态访问的queue里
 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
map<char,array<int,4>> mp//存的是反射的方向
{
    {'-', {1,0,2,3}},
    {'|', {0,1,3,2}},
    {'/', {3,2,1,0}},
    {'\\',{2,3,0,1}}
};
PII dfs(int x,int y,int status){//没有情况操作
    //越界则为链
    if(x>n || x<1 || y>m || y<1) return{0,0};
    //记忆化
    if(memory[x][y][status]){//如果已经搜过了
        tag=id[x][y][status];//把询问改成之前已有的询问
        return{memory[x][y][status],0};
    }
    //在这次询问中遇环返回
    if(id[x][y][status]==tag) return{0,1};//如果成环了
    id[x][y][status]=tag;
 
    int dir=mp[a[x][y]][status];
    int tx=x+dx[dir];
    int ty=y+dy[dir];
    //接着跑
    auto[ans,flag]=dfs(tx,ty,dir);
    //如果经过的点发生了反射
    if(status!=dir){
        memory[x][y][status]=1;
        for(int i=0;i<4;i++){
            if(used[x][y][i]==tag) memory[x][y][status]=0;//这是特殊情况，如果已经反射过了，要设置成0
        }
        used[x][y][status]=tag;
    }
    id[x][y][status] = tag;
    //若成环则将经过的点加入path
    if(flag) path.push_back({x,y,status});
    return{memory[x][y][status]+=ans,flag};
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    cin>>q;
    int cnt=0;
    while(q--){
        int x,y;cin>>x>>y;
        string s;cin>>s;
        int status;
        //上下左右
        if(s=="above")      status=0;
        else if(s=="below") status=1;
        else if(s=="left")  status=2;
        else if(s=="right") status=3;
        int tx=x+dx[status];
        int ty=y+dy[status];
        cnt++;tag=cnt;
        //注意：起点不算反射
        //ans：答案  flag：搜索过程中是否为环
        auto[ans,flag]=dfs(tx,ty,status);
        cout<<ans<<endl;
        if(flag){
            for(auto[x,y,status]:path) memory[x][y][status]=ans;
            path.clear();//对成环的进行修改
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    while(T--) solve();
}