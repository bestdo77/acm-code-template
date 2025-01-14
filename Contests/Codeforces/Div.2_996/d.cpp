#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n,k,l;cin>>n>>k>>l;
    vector<double> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    double cost=a[1];
    double pos=k;
    for(int i=2;i<=n;i++){
        // cout<<cost<<" "<<pos<<endl;
        if(a[i]<=pos){
            pos=a[i]+min(pos-a[i],cost)+k;
        }else{
            if(a[i]-pos>cost){
                double tmp=(a[i]-pos-cost)/2.0;
                pos=(a[i]-cost+pos)/2.0+k;
                cost+=tmp;
            }else{
                pos=pos+k;
            }
        }
    }
    // cout<<cost<<endl;
    // cout<<pos<<endl;
    if(pos<=l){
        cost+=(l-pos);
    }
    cout<<(int)(2ll*cost)<<endl;
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