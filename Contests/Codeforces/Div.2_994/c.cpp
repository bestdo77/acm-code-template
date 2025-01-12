#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,x,y;cin>>n>>x>>y;
    if(n%2){
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++){
            if(i==1) a[i]=2;
            else if(i%2) a[i]=1;
            else a[i]=0;
        }
        if(a[x]==a[y]&&x!=2) a[x]=2;
        else if(a[x]==a[y]){
            a[1]=0;
            a[2]=2;
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }else{
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2) a[i]=0;
            else a[i]=1;
        }
        if(a[x]==a[y]) a[x]=2;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
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