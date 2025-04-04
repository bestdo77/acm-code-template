#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
int a[N1][N1];
int cnt[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<=n*m;i++) cnt[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i+1][j]==a[i][j]||a[i-1][j]==a[i][j]||a[i][j-1]==a[i][j]||a[i][j+1]==a[i][j]){
                cnt[a[i][j]]=2;
            }else if(cnt[a[i][j]]==0) cnt[a[i][j]]=1;
        }
    }
    int ans=0;
    int mx=0;
    for(int i=1;i<=n*m;i++){
        ans+=cnt[i];
        mx=max(cnt[i],mx);
    }
    cout<<ans-mx<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}