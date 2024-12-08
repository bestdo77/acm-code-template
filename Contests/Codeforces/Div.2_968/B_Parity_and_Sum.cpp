#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int ou[N],p;
void solve(){
    int n;cin>>n;
    p=0;
    int mj=0,mou=0,cntj=0,cntou=0,minou=inf;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]%2) cntj++,mj=max(mj,a[i]);
        else cntou++,mou=max(mou,a[i]),minou=min(minou,a[i]);
    }
    if(cntou==0||cntj==0){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==0) ou[++p]=a[i];
    }
    sort(ou+1,ou+1+p);
    int ans=0;
    bool flag=0;
    for(int i=1;i<=p;i++){
        if(mj>=ou[i]) ans++,mj+=ou[i];
        else if(!flag) ans+=2,mj+=ou[p],flag=1;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}