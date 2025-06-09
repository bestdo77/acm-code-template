#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
int hav[N1][N1];
string s[N1];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    vector<int> vis(n+1,0);
    int mx=0;
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            string s1;cin>>s1;
            hav[i][j]=(s1==s[j]);
            if(hav[i][j]) vis[j]=1;
            cnt+=hav[i][j];
        }
        mx=max(mx,cnt);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<n+2*(n-mx)<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}