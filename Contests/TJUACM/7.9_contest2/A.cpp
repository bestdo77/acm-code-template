#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int MAXN=1e3+10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        double n;cin>>n;
       if(n==1||n==2){
           cout<<0<<'\n';
           continue;
       }else if(n==3||n==4){
           cout<<1<<'\n';
       		continue;
       }else{
           int ans=ceil(1.0*log2(n*1.0));
            //cout<<ans<<"kk\n";
           ans--;
           cout<<(1ll<<ans)-1<<"\n";
       }
        
    }
    return 0;
}