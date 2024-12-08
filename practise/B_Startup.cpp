#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int ans[N];
bool cmp(int x,int y){
    return x>y;
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }   
    for(int i=1;i<=m;i++){
        int id,v;cin>>id>>v;
        ans[id]+=v;
    }

    sort(ans+1,ans+1+m,cmp);
    cout<<accumulate(ans+1,ans+1+min(n,m),0)<<endl;
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