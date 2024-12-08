#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
// vector<int> but[N];
void Atomatic_AC_machine(){
    int n,d,k;cin>>n>>d>>k;
    vector<int> but(n+2),dec(n+2);
    for(int i=1;i<=k;i++){
        int l,r;cin>>l>>r;
        but[l]++;
        dec[r+1]++;
    }
    for(int i=1;i<=n+1;i++){
        but[i]+=but[i-1];
        dec[i]+=dec[i-1];
    }
    int mx=0,mn=inf,mxpos,mnpos;
    for(int i=1;i+d-1<=n;i++){
        int ans=but[i+d-1]-dec[i];
        if(ans>mx) mx=ans,mxpos=i;
        if(ans<mn) mn=ans,mnpos=i;
    }
    cout<<mxpos<<" "<<mnpos<<endl;
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