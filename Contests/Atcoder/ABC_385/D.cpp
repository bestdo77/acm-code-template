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
map<int,set<pii>> line,col;
int vis[N];
int n,m,x,y,ans;
void del(set<pii> &st,int l,int r){
    while(1){
        auto it=st.lower_bound({l,0});
        if(it==st.end()||it->first>r) return;
        if(!vis[it->second]) vis[it->second]=1,++ans;
        st.erase(it);
    }
}
void Atomatic_AC_machine(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        int xx,yy;cin>>xx>>yy;
        line[xx].insert({yy,i});
        col[yy].insert({xx,i});
    }
    for(int i=1;i<=m;i++){
        char op;int d;
        cin>>op>>d;
        if(op=='D') del(line[x],y-d,y),y-=d;
        if(op=='U') del(line[x],y,y+d),y+=d;
        if(op=='L') del(col[y],x-d,x),x-=d;
        if(op=='R') del(col[y],x,x+d),x+=d;
    }
    cout<<x<<" "<<y<<" "<<ans<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}