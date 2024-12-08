#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<vector<int> > > dp (710);//第一维线树，二维种类，三维每种的个数
    vector<vector <int> > ans (710);//表示每种情况的答案
    dp[3][1].push_back(3);
    dp[3][2].push_back(2);
    dp[3][2].push_back(1);
    dp[3][3].push_back(1);
    dp[3][3].push_back(1);
    dp[3][3].push_back(1);
    ans[3][1]=0;
    ans[3][2]=2;
    ans[3][3]=3;
    for(int i=4;i<=700;i++){
        int cnt=0;
        for(int j=1;j<dp[i].size();j++){
            int ans=0;
            for(int k=0;k<dp[i][j].size();k++){
                
            }
        }
    }
    return 0;
}