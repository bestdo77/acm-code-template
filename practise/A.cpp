#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
char ans[1000][1000];
void dfs(int x1,int x2,int y1,int y2){
    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    if(x1==x2&&y1==y2){
        ans[x1][y1]='X';
        return;
    }
    int len=(x2-x1+1)/3;
    dfs(x1,x1+len,y1,y1+len);
    dfs(x1+2*len,x1+3*len,y1,y1+len);
    
    dfs(x1+len,x1+2*len,y1+len,y1+2*len);
    
    dfs(x1,x1+len,y1+2*len,y1+3*len);
    dfs(x1+2*len,x1+3*len,y1+2*len,y1+3*len);
}
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int mx=pow(3,7-1);
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
            ans[i][j]=' ';
        }
    }
    // cout<<mx<<endl;
    dfs(1,mx,1,mx);
    int t;
    while(cin>>t){
    if(t==-1) return 0;
       for(int i=1;i<=pow(3,t-1);i++){
            for(int j=1;j<=pow(3,t-1);j++){
                cout<<ans[i][j];
            }cout<<endl;
        }
        cout<<"-"<<endl;
    }
    return 0;
}