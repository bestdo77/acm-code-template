#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
vector<int> G[N];
set<int> sets;
void Atomatic_AC_machine(){
    int l,a,b;cin>>a>>b>>l;
    int cnt=0;
    for(int x=0;x<=30;x++){
        for(int y=0;y<=30;y++){
            int ax=pow(a,x);
            int by=pow(b,y);
            if(ax*by>l||ax*by<=0) break;
            if((l%(ax*by))==0&&(l/(ax*by)>=0)) sets.insert(l/(ax*by));
        }
    }
    cout<<sets.size()<<endl; 
    sets.clear();
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