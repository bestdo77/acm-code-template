#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int a[5100][5100];
int b[5100][5100];
int lefts[5100];
int rights[5100];
struct node{
    int x,pos;
}line[5100];
const int MAXN=1e3+10;
int n,m;
int ans=0;
void dandzhan(int l){//修改left，right数组
    for(int i=1;i<=m;i++){
        line[i].x=b[l][i];
        line[i].pos=i;
    }
    stack<node> stacks;//先正着弄；
    stacks.push(node{0,m+1});
    for(int i=m;i>=1;i--){
        while(line[i].x<=stacks.top().x){
            stacks.pop();
        }
        rights[i]=stacks.top().pos-line[i].pos;
        stacks.push(line[i]);
    }
    if(!stacks.empty()) stacks.pop();
    stacks.push(node{0,0});
    for(int i=1;i<=m;i++){
        while(line[i].x<=stacks.top().x){
            stacks.pop();
        }
        lefts[i]=line[i].pos-stacks.top().pos;
        stacks.push(line[i]);
    }
    // for(int i=1;i<=m;i++){
    //     cout<<lefts[i]<<" "<<rights[i]<<endl;
    // }
    for(int i=1;i<=m;i++){

        ans=max(ans,line[i].x*(rights[i]+lefts[i]-1));
        // cout<<ans<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1) b[i][j]=1;
                else if(a[i][j]>=a[i-1][j]) b[i][j]=b[i-1][j]+1;
                else b[i][j]=1;
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<b[i][j]<<" ";
        //     }cout<<endl;
        // }
        for(int i=1;i<=n;i++) dandzhan(i);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}