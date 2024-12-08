#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
#pragma GCC optimize(3,"Ofast","inline")
const int N=1000050;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while (c<'0' || c>'9'){
        if (c=='-')  f=-1;
        c=getchar();
    }
    while (c>='0' && c<='9'){
        x=x*10+c-'0';
         c=getchar();
    }
    return x*f;
}
inline void print(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
    return ;
}
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
int n,m;
int S_,T_;
int NOW[N],DIS[N];
int BFS_(){
    //memset(DIS, 0x3f,sizeof DIS);//<-注意数据范围：如果需要开ll，应该改掉inf
    for (int i=1;i<=n*2+5;i++){
        DIS[i]=inf;
    }
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
    //最坏时间复杂度:O(V^2·E)
    //单位容量(w=1)网络时间复杂度:O(E·min((E^(1/2),V^(2/3))
}

int vis[N*2]; 
queue <int>q;
int  BFS(int st,int ss,int tt,int check){
    int ret=0;
    for (int i=1;i<=n*2+5;i++){
        vis[i]=0;
    }
   
    q.push (st);
    while (!q.empty()){
        int tem=q.front();
     //   cout <<tem<<endl;
        q.pop();
        for (int i=HEAD_[tem];i!=-1;i=E_[i].nxt){
            int v=E_[i].to;
            if (E_[i].w==check)if (!vis[v]){
                vis[v]=1;
                ret+=(v>=ss&&v<=tt);
                q.push(v);
            }
        }
    }
    return ret;
}

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t=read();
    while (t--){
        
        n=read();
        m=read();
        S_=n*2+1,T_=n*2+2;
        INIT(n*2+5);
        for (int i=1;i<=n;i++){
            ADD(S_,i,1);
        }
        for (int i=1+n;i<=n+n;i++){
            ADD(i,T_,1);
        }
        for (int i=1;i<=m;i++){
            int tem1,tem2;
            tem1=read();
            tem2=read();
            ADD(tem1,tem2+n,1);
        }
        Dinic();
       // Dinic();
        int cnt1=0,cnt2=0;
        cnt1=BFS(S_,1,n,1);
        cnt2=BFS(T_,n+1,n*2,0);
        print(cnt1*cnt2);
        putchar('\n');
    }
}