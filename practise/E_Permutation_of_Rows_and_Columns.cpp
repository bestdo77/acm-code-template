#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int mod=1e9+7;
const int element=3;
vector<vector<int>> a(N),b(N);
set<int> cola[N],colb[N],lina[N],linb[N];
bool cmp(set<int> a,set<int> b){
    if(a.size()==b.size()) return *a.begin()<*b.begin();
    else return a.size()<b.size();
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].push_back(0);
        for(int j=1;j<=m;j++){
            int x;cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        b[i].push_back(0);
        for(int j=1;j<=m;j++){
            int x;cin>>x;
            b[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            lina[i].insert(a[i][j]);
            linb[i].insert(b[i][j]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            cola[j].insert(a[i][j]);
            colb[j].insert(b[i][j]);
        }
    }
    sort(cola+1,cola+1+m,cmp);
    sort(colb+1,colb+1+m,cmp);
    sort(lina+1,lina+1+n,cmp);
    sort(linb+1,linb+1+n,cmp);
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(lina[i]!=linb[i]){
            flag=0;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(cola[i]!=colb[i]){
            flag=0;
            break;
        }
    }
    // cout<<*linb[2].begin();
    // for(int i=1;i<=m;i++){
    //     cout<<"a: ";
    //     for(auto it:cola[i]) cout<<it<<" ";
    //     cout<<"b: ";
    //     for(auto it:colb[i]) cout<<it<<" ";
    //     cout<<endl;
    // }
    if(!flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    for(int i=1;i<=m;i++){
        cola[i].clear();
        colb[i].clear();
    }
    for(int i=1;i<=n;i++){
        lina[i].clear();
        linb[i].clear();
    }
    for(int i=1;i<=n;i++){
        a[i].clear();
        b[i].clear();
    }
    return;
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