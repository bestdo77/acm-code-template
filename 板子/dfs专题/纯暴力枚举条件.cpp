#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int MAXN=100;
int n;
bool fx[MAXN],fy[MAXN],tx[MAXN][3],ty[MAXN][3];//fx,fy表示是否被使用过，tx,ty表示是否ABC用过
char a[MAXN],b[MAXN],ans[MAXN][MAXN];
void print(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cout<<ans[i][j];
        cout<<endl;
    }
}
void dfs(int x,int y,int tot){
    if(y>n) x++,y=1;
    if(x>n){
        if(tot==3*n){
            cout<<"Yes"<<endl;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j) cout<<ans[i][j];
                cout<<endl;
            }
            exit(0);//这块dfs搜到了直接退出。
        }
        return;
    }
    for(int i=0;i<3;i++){
        if(!tx[x][i]&&!ty[y][i]){
            bool flag1=fx[x],flag2=fy[y];
            if(!fx[x]&&i!=a[x]-'A') continue;
            if(!fy[y]&&i!=b[y]-'A') continue;
            fx[x]=fy[y]=tx[x][i]=ty[y][i]=1;
            ans[x][y]=i+'A';
            // print();
            dfs(x,y+1,tot+1);
            fx[x]=flag1;fy[y]=flag2;
            tx[x][i]=ty[y][i]=0;
        }
    }
    ans[x][y]='.';
    dfs(x,y+1,tot);
}
signed main(){
    cin>>n;
    scanf("%s%s",a+1,b+1);
    dfs(1,1,0);
    cout<<"No"<<endl;
    return 0;
}