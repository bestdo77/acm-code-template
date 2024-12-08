#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
vector<int> a[10];
void Atomatic_AC_machine(){
    for(int i=1;i<=9;i++){
        int t=i;
        while(t<=1e10){
            a[i].push_back(t);
            t=t*10+i;
        }
    }
    int n;cin>>n;
    // for(int i=1;i<=9;i++){
    //     for(auto it: a[i]){
    //         cout<<it<<" ";
    //     }cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=9;i++){
        ans+=upper_bound(a[i].begin(),a[i].end(),n)-a[i].begin();
        // cout<<upper_bound(a[i].begin(),a[i].end(),n)-a[i].begin()<<endl;
    }
    int ze=10;
    int t=1;
    while(ze<=n){
        ze*=10;
        t++;
    }
    if(ze==10) ans+=1;
    else ans+=t-1;
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