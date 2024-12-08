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
bool check(int x){
    return x==(int)sqrt(x)*(int)sqrt(x);
}
void Atomatic_AC_machine(){
    for(int i=1;i<=sqrt(N);i++){
        for(int j=1;j<=sqrt(N);j++){
            for(int k=1;k<=sqrt(N);k++){
                    int a=i*i,b=j*j,c=k*k,d=a+b+c;
                    if(check(b+a)&&check(c+b)&&check(d)){
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    }
            }
        }
    }
    cout<<check(1)<<endl;
    for(int i=1;i<=sqrt(100);i++){
        for(int j=i+1;j<=sqrt(100);j++){
            if(check(j*j-i*i)){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
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