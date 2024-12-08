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
int ton[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
    }
    for(int i=1;i<=n-1;i++){
        if(a[i]==a[i+1]+1){
            swap(a[i],a[i+1]);
        }
        if(a[i]!=i){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(a[n]!=n){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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