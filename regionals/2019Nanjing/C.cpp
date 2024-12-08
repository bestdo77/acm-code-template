#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x,y,val;
    bool operator < (const node &a)const{
        return val<a.val;
    }
};
vector<node> a;
const int N1=1100;

int mp[N1][N1];
int dp[N1][N1][10];
const int mod=1e9+7;
int dx[10]={1,-1,0,0};
int dy[10]={0,0,1,-1};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin >>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                a.push_back({i,j,mp[i][j]});
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j][1]=1;
            }
        }
        sort(a.begin(),a.end());
        int res=0;
        for(int i = 0;i<n*m;i++){
            int x = a[i].x,y = a[i].y,val = a[i].val;
            int flag=0;
            for (int j=0;j<=3;j++){
                int temx=x+dx[j],temy=y+dy[j];
                if (temx>0&&temx<=n&&temy>0&&temy<=m){
                    if (mp[temx][temy]==val+1){
                        flag=1;
                        dp[temx][temy][1]=0;
                        (dp[temx][temy][2]+=dp[x][y][1])%=mod;
                        (dp[temx][temy][3]+=dp[x][y][2])%=mod;
                        (dp[temx][temy][4]+=dp[x][y][3])%=mod;
                        (dp[temx][temy][4]+=dp[x][y][4])%=mod;
                    }
                }
            }
            if (flag==0)res+=dp[x][y][4];
            res%=mod;
        }
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=m;j++){
        //         cout <<dp[i][j][4]<<' ';
        //     }
        //     cout <<endl;
        // }
        cout <<res%mod<<endl;
    }
}