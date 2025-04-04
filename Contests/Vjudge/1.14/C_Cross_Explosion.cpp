#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
set<int> h[N],w[N];
int sz;
void del(int x,int y){
    // cerr<<x<<" "<<y<<endl;
    if(h[x].find(y)==h[x].end()||w[y].find(x)==w[y].end()){
        assert(0);
    }
    h[x].erase(y);
    w[y].erase(x);
    sz--;
}
void Atomatic_AC_machine(){
    int n,m,k;cin>>n>>m>>k;
    sz=n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            h[i].insert(j);
            w[j].insert(i);
        }
    }
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        if(h[x].find(y)!=h[x].end()&&w[y].find(x)!=w[y].end()){
            del(x,y);
            continue;
        }
        auto hyr=h[x].lower_bound(y);
        auto wxr=w[y].lower_bound(x);
        if(hyr!=h[x].begin()){
            auto hyl=prev(hyr);
            del(x,*hyl);
        }
        if(wxr!=w[y].begin()){
            auto wxl=prev(wxr);
            del(*wxl,y);
        }
        if(hyr!=h[x].end()){
            del(x,*hyr);
        }
        if(wxr!=w[y].end()){
            del(*wxr,y);
        }
    }
    cout<<sz<<endl;
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