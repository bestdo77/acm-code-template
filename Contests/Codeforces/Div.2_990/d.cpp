#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int b[N];
int sufmin[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++){
        sufmin[i]=inf;
    }
    for(int i=n;i>=1;i--){
        sufmin[i]=min(sufmin[i+1],a[i]);
    }
    int mn=inf;
    for(int i=1;i<=n;i++){
        // cout<<mn<<" ";
        if(a[i]>min(sufmin[i],mn)){
            a[i]++;
            mn=min(a[i],mn);
        }    
    }
    // cout<<endl;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
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