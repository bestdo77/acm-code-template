#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;


struct EDGE_{
    int to,w,nxt;
}E_[N];
int HEAD_[N],cnt;
//链式前向星存图：HEAD[i]是i最后出现的位置，nxt是这个点为出点的上一个位置。

void INIT(int n){
    for (int i=0;i<=n;i++)HEAD_[i]=-1;
    cnt=0;
}

void ADD1(int u,int v,int w){
    E_[cnt].nxt=HEAD_[u];
    E_[cnt].to=v;
    E_[cnt].w=w;
    HEAD_[u]=cnt++;
}

void ADD(int u,int v,int w){
    ADD1(u,v,w);
    ADD1(v,u,0);
}

int S_,T_;
int NOW[N],DIS[N];
int BFS_(){
    memset(DIS, 0x3f,sizeof DIS);//<-注意数据范围：如果需要开ll，应该改掉inf
    queue<int> q;
    q.push(S_);
    DIS[S_]=0;
    NOW[S_]=HEAD_[S_];
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int i=HEAD_[u];i!=-1;i=E_[i].nxt){
            int v=E_[i].to;
            if(E_[i].w>0&&DIS[v]==inf){
                q.push(v);
                NOW[v]=HEAD_[v];
                DIS[v]=DIS[u]+1;
                if(v==T_)return 1;
            }
        }
    }
    return 0;
}
int DFS_(int u,int sum){
    if(u==T_)return sum;
    int k,res=0;
    for (int i=NOW[u];(i!=-1)&&sum;i=E_[i].nxt){
        NOW[u]=i;
        int v=E_[i].to;
        if(E_[i].w>0&&(DIS[v]==DIS[u]+1)){
            k=DFS_(v,min(sum,E_[i].w));
            if(k==0)DIS[v]=inf;
            E_[i].w-=k;
            E_[i^1].w+=k;
            res+=k;
            sum-=k;
        }
    }
    return res;
}
int Dinic(){
    int res=0;
    while (BFS_()){
        res+=DFS_(S_,inf);
    }
    return res;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >>n>>m>>S_>>T_;
    INIT (n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin >>u>>v>>w;
        ADD(u,v,w);
    }
    cout <<Dinic()<<endl;
}