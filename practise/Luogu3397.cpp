#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1100][1100];
int b[1100][1100];
int sum[1100][1100];
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j) cin>>a[i][j];
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         b[i][j]=a[i][j]-a[i-1][j]-a[j][i-1]+a[i-1][j-1];
    //     }
    // }
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        b[x1][y1]++;
        b[x2+1][y2+1]++;
        b[x2+1][y1]--;
        b[x1][y2+1]--;
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}