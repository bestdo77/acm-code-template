#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
void solve(){
    int n,m;cin>>n>>m;
    bool v1,v2;cin>>v1>>v2;//v1短，v2长
    cout<<v1<<" "<<v2<<endl;
    if(!v1&&!v2){
        if(n==1&&m==2||n==2&&m==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else if(v1&&!v2){
        if(n==1&&m%2==0||n%2==0&&m==1){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }else if(!v1&&v2){
        if(n%2==0||m%2==0){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }else if(v1&&v2){
        if(n%2&&m%2) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}   
signed main(){
    cout<<(1<<25)<<endl;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}