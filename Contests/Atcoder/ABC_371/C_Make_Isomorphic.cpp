#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N1][N1]; 
int mp1[N1][N1],mp2[N1][N1],cost[N1][N1];
map<pii,bool> ls,nw;
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mp1[u][v]=1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mp2[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    int cn[10]={0,1,2,3,4,5,6,7,8,9};
    int res=inf;
    do{
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int xx=cn[i],yy=cn[j];
                if(xx>yy) swap(xx,yy);
                if(mp1[i][j]!=mp2[xx][yy]) ans+=cost[xx][yy];
            }
        }
        res=min(res,ans);
    }while(next_permutation(cn+1,cn+n+1));
    cout<<res<<endl;
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