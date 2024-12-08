#include <cstdio>
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn=2e3+10;
int dp[maxn][maxn];
int gh[maxn][maxn];
int l[maxn],r[maxn];
struct point{
    int v,x;
    point(){
        v=0;x=0;
    }
    point(int _v,int _x){v=_v;x=_x;}
};
int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&gh[i][j]);
            }
        }
        int ans=m;
        for(int i=2;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                dp[1][j]=1;
                if(gh[i][j]>=gh[i-1][j]) dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=1;
            }
        }
        for(int i=2;i<=n;i++){
            l[1]=1;r[m]=1;
            stack<point> s;
            s.push(point(0,0));
            for(int j=1;j<=m;j++){
                while(!s.empty()){
                    point now=s.top();
                    if(now.v>=dp[i][j]){s.pop();continue;}
                    else{l[j]=j-now.x;
                    s.push(point(dp[i][j],j));
                    break;
                    }
                }
            }
            while(!s.empty()) s.pop();
            s.push(point(0,m+1));
            for(int j=m;j>=1;j--){
                
                while(!s.empty()){
                    point now=s.top();
                    if(now.v>=dp[i][j]){s.pop();continue;}
                    else{r[j]=now.x-j;
                    s.push(point(dp[i][j],j));
                    break;
                    }
                }
            }
            for(int j=1;j<=m;j++){
                if(dp[i][j]==1) continue;
                ans=max(ans,dp[i][j]*(l[j]+r[j]-1));
            }
       }
       printf("%d\n",ans);
    }
}