#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e3+10;
const int mod=1e9+7;
int a[N][N],b[N][N];
int n,m;
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==b[i][j]) return false;
        }
    }
    return true;
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        bool flag=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int t=1;t<n*m;t++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    int num=(i-1)*(m)+j;
                    num+=t;
                    if(num>n*m) num-=n*m;
                    int x=num/m+1;
                    int y=num%m;
                    if(y==0) y=m,x--;
                    b[x][y]=a[i][j];
                }
            }
            // print();
            if(check()){
                print();
                flag=1;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}