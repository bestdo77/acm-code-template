#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
int a[16]={0,6,3,3,3,6,2,3,1,6,2,3,6,6,6,3};
int a1[7]={0,1,1,2,3,1,2};
int a2[10]={0,7,3,3,7,5,3,7,7,3};
void Atomatic_AC_machine(){
    int n;cin>>n;
    if(n>=15){
        for(int i=1;i<=15;i++){
            cout<<a[i]<<" ";
        }
        for(int i=1;i<=n-15;i++){
            cout<<i+6<<" ";
        }
    }else if(n>=9){
        for(int i=1;i<=9;i++){
            cout<<a2[i]<<" ";
        }
        for(int i=1;i<=n-9;i++){
            cout<<i+7<<" ";
        }
    }else{
        for(int i=1;i<=6;i++){
            cout<<a1[i]<<" ";
        }
        for(int i=1;i<=n-6;i++){
            cout<<3<<" ";
        }
    }
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