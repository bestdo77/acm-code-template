#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e7+10;
const int mod=1e9+7;
int n,len,a[N],b[N];
int des[N],jp[N];
void modify(int x,int c){
    a[x]=c;
    for(int i=x;i>=(b[x]-1)*len+1;i--){
        if(i+a[i]>n) des[i]=n+1,jp[i]=1;
        else if(b[a[i]+i]!=b[i]) des[i]=a[i]+i,jp[i]=1;
        else jp[i]=jp[a[i]+i]+1,des[i]=des[a[i]+i];
    }
}
int query(int x){
    int ret=0;
    while(x<n+1){
        ret+=jp[x];
        x=des[x];
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=(i-1)/len+1;//记录元素所属分块
    }
    // cout<<b[1]<<endl;
    for(int i=n;i>=1;i--){
        if(i+a[i]>n) des[i]=n+1,jp[i]=1;
        else if(b[a[i]+i]!=b[i]) des[i]=a[i]+i,jp[i]=1;
        else jp[i]=jp[a[i]+i]+1,des[i]=des[a[i]+i];
    }
    int m;cin>>m;
    int opt,l,x,v;
    for(int i=1;i<=m;i++){
        cin>>opt>>x;
        if(opt==2){
            cin>>v,modify(x+1,v);
        }
        else cout<<query(x+1)<<endl;
    }
    return 0;
}