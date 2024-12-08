#include <bits/stdc++.h>
using namespace std;
#define pii pair <int,int>
int dpo[105][105];
int dpe[105][105];
struct node {
    int x;int y;int w;
};
queue<node>qu;
int x,y,p,q;
void BFS(int sx,int sy){
    qu.push ({sx,sy,0});
    while (!qu.empty()){
        node tem=qu.front();
       // if (tem.w!=0)break;;
        int temx=tem.x,temy=tem.y;int temw=tem.w;
        qu.pop();
       // cout <<temw<<" ";
        for (int i=0;i<=x;i++){
            for (int j=0;j<=y;j++){
                if (temw%2==0){
                   // cout <<i<<" "<<j<<" "<<temx+temy-i-j<<endl;
                    if (dpo[i][j]!=-1)continue;
                    if (temx+temy-i-j<=p&&i<=temx&&j<=temy){
                        if (j<=i+q||i==0){
                            dpo[i][j]=temw+1;
                            qu.push({i,j,dpo[i][j]});
                        }
                    }
                }else{
                    if (dpe[i][j]!=-1)continue;
                    if (i+j-temx-temy<=p&&i>=temx&&j>=temy){
                        
                        if (y-j<=x-i+q||x-i==0){
                            dpe[i][j]=temw+1;
                            qu.push({i,j,dpe[i][j]});
                        }
                    }
                }
            }
        }
    }

}

int main (){
    cin>>x>>y>>p>>q;
    memset (dpo,-1,sizeof dpo);
    memset (dpe,-1,sizeof dpe);
    dpe[x][y]=0;
    BFS(x,y);
    // for (int i=0;i<=x;i++){
    //     for (int j=0;j<=y;j++){
    //         cout <<dpo[i][j]<<" ";..........
    //     }
    //     cout <<endl;
    // }
    // for (int i=0;i<=x;i++){
    //     for (int j=0;j<=y;j++){
    //         cout <<dpe[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    int ans=0x3f3f3f3f3f;
    for (int i=0;i<=y;i++){
        if (dpo[0][i]!=-1)ans=min(ans,dpo[0][i]);
        if (dpe[0][i]!=-1)ans=min(ans,dpe[0][i]);
    }
    if (ans==0x3f3f3f3f)cout <<-1<<endl;
    else cout <<ans<<endl;
}