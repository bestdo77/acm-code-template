#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int vis[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    n-=2;
    for(int i=1;i<=n+2;i++){
        if(n%a[i]==0){
            int p=n/a[i];
            if(p==a[i]&&vis[p]>=2){
                cout<<p<<" "<<p<<endl;
                return;
            }else if(vis[p]>=1&&p!=a[i]){
                cout<<a[i]<<" "<<p<<endl;
                return;
            }
        }
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