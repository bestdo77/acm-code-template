#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string s[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    for(int i=1;i<=n/2;i++){
        for(int x=i;x<=n-i+1;x++){
            for(int y=x;y<=n-i+1;y++){
                s[y][n+1-x]=s[x][y];
            }
        }
        for(int y=i;y<=n-i+1;y++){
            for(int x=y;x<=n-i+1;x++){
                s[y][n+1-x]=s[x][y];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<s[i][j];
            }cout<<endl;
        }
        cout<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}