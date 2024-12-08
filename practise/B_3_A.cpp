#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> ans,pow3(30);
    pow3[0]=1;
    for(int i=1;i<=15;i++){
        pow3[i]=pow3[i-1]*3;
    }
    for(int i=15;i>=0;i--){
        while(n>=pow3[i]){
            ans.push_back(i);
            n-=pow3[i];
        }
        if(n==0) break;
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
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