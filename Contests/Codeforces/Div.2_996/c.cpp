#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N1][N1];
int line[N1];
int col[N1];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int cc=0;
    if(n==m){
        cc=n;
    }
    for(int i=1;i<=n;i++){
        line[i]=0;
    }
    for(int j=1;j<=m;j++){
        col[j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            line[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    }
    int xx=1,yy=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='D'){
            int num=line[xx]-a[xx][yy];//找剩余的一行
            int tmp=cc-num;
            line[xx]=line[xx]+tmp-a[xx][yy];
            col[yy]=col[yy]+tmp-a[xx][yy];
            a[xx][yy]=tmp;
            xx++;
        }else{
            int num=col[yy]-a[xx][yy];
            int tmp=cc-num;
            line[xx]=line[xx]+tmp-a[xx][yy];
            col[yy]=col[yy]+tmp-a[xx][yy];
            a[xx][yy]=tmp;
            yy++;
        }
    }
    
    a[n][m]=line[n-1]-line[n];

    // for(int i=1;i<=n;i++){
    //     cout<<line[i]<<" ";
    // }
    // cout<<endl;
    // for(int j=1;j<=m;j++){
    //     cout<<col[j]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}