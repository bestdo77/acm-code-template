#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
map<int,int> cntx,cnty;
map<pii,int> val;
void Atomatic_AC_machine(){
    int n;cin>>n;
    int mx=0,x1,y1;
    int my=0,x2,y2;
    for(int i=1;i<=n;i++){
        int r,c,x;cin>>r>>c>>x;
        cntx[r]+=x;
        cnty[c]+=x;
        if(cntx[r]>mx){
            mx=cntx[r];
            x1=r,y1=c;
        }
        if(cnty[c]>my){
            my=cnty[c];
            x2=r,y2=c;
        }
        val[make_pair(r,c)]=x;
    }
    int ans=0;
    for(auto it:cnty){//用mx去更新
        ans=max(mx+it.second-val[{x1,it.first}],ans);
    }
    for(auto it:cntx){
        ans=max(my+it.second-val[{it.first,y2}],ans);
    }
    cout<<ans<<endl;
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