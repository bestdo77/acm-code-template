#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// #define int long long
const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    if(k>1){
        if(n==1){
            for(int i=2;i<=k;i++){
                n=n*10+1;
            }
            if(n==1){
                cout<<"NO"<<endl;
                return;
            }
           for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl; 
        }else cout<<"NO"<<endl;
    }else{
        if(n==1){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}