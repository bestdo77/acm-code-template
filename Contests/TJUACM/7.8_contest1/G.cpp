#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
char maps[1000][1000];
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>maps[i][j];
    }
    char sign=maps[1][1];
    char sign2=maps[2][1];
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||i+j==n+1){
                if(maps[i][j]!=sign){
                    flag=0;break;
                }
            }else{
                if(maps[i][j]!=sign2){
                    flag=0;break;
                }
            }
            if(sign==sign2){
                flag=0;break;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}