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
    if(n<5){
        cout<<-1<<endl;
        return;
    }else{
        for(int i=1;i<=n/2;i++){//先偶数
            if(i!=2) cout<<2*i<<" ";
        }
        cout<<"4 5 ";
        for(int i=1;i<=n/2+n%2;i++){
            if(i!=3) cout<<2*i-1<<" ";
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