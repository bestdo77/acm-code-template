#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int ans[28]={0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,10,11,11,13,12,12,1,13};
void Atomatic_AC_machine(){
    int n;cin>>n;
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
    }else{
        if(n>=27){
            for(int i=1;i<=27;i++){
                cout<<ans[i]<<" ";
            }
            int tt=n-27;
            for(int i=1;i<=tt/2;i++){
                cout<<i+13<<" "<<i+13<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
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