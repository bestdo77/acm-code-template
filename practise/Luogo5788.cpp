#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
struct node{
    int x,pos;
}a[3100000];
int ans[3100000];
stack<node> stacks;
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].pos=i;
    }
    node tmp={inf,0};
    stacks.push(tmp);
    for(int i=n;i>=1;i--){
        while(a[i].x>=stacks.top().x){
            stacks.pop();
        }
        ans[i]=stacks.top().pos;
        stacks.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}