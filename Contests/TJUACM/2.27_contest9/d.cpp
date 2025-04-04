#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int d[N1][N1];
char mp[N1][N1];
void Atomatic_AC_machine(){
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>mp[i][j];
        }
    }
    int n=h*w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=inf;
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int p1=(i-1)*w+j;
            if(j+1<=w&&mp[i][j]=='.'&&mp[i][j+1]=='.'){
                d[p1][p1+1]=d[p1+1][p1]=1;
            }
            if(i+1<=h&&mp[i+1][j]=='.'&&mp[i][j]=='.'){
                d[p1][p1+w]=d[p1+w][p1]=1;
            } 
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]!=inf) ans=max(ans,d[i][j]);
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}