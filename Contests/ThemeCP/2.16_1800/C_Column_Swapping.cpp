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
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    int a[n+1][m+1],a1[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            a1[i][j]=a[i][j];
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        sort(a1[i]+1,a1[i]+1+m);
        int tmp1=0,tmp2=0;
        for(int j=1;j<=m;j++){
            if(a[i][j]!=a1[i][j]){
                if(tmp1&&tmp2){
                    cout<<-1<<endl;
                    return;
                }
                if(tmp1) tmp2=j;
                else tmp1=j;
            }
        }
        if(tmp1&&tmp2){
            ans1=tmp1;
            ans2=tmp2;
        }
    }
    for(int i=1;i<=n;i++){
        swap(a[i][ans1],a[i][ans2]);
    }
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]>a[i][j+1]) flag=0;
        }
    }
    if(m==1||ans1==0) cout<<"1 1"<<endl;
    else{
        if(flag) cout<<ans1<<" "<<ans2<<endl;
        else cout<<-1<<endl;
    }
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