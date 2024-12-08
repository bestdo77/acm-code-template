#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000],b[5100000];
const int MAXN=1e3+10;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    for(int j=1;j<=m;j++){
        int x,y;cin>>x>>y;
        cout<<a[x-y]<<endl;
    }
    return 0;
}