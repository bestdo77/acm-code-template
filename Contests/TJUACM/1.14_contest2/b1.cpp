#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int C[N],r[N];
struct pii
{
    int first,second;
};

bool cmp(pii a,pii b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}
void Atomatic_AC_machine(){
    int n,c;cin>>n>>c;
    vector<pii> cc;
    vector<pii> nc;
    for(int i=1;i<=n;i++){
        cin>>C[i];
    }
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        if(C[i]==c) cc.emplace_back(pii{r[i],i});
        if(C[i]==C[1]) nc.emplace_back(pii{r[i],i});
    }
    sort(cc.begin(),cc.end(),cmp);
    sort(nc.begin(),nc.end(),cmp);
    if(cc.size()){
        cout<<cc.back().second<<endl;
    }else{
        cout<<nc.back().second<<endl;
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