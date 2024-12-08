#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int fib1[N],fib2[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=2;i<=50;i++){
        if(i==2) cout<<i<<" "<<n<<endl;
        else{
            if((n-fib1[i])%fib2[i]==0) cout<<i<<" "<<(n-fib1[i])/fib2[i]<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fib1[1]=1;
    fib1[2]=0;
    fib2[1]=0;
    fib2[2]=1;
    for(int i=3;i<=50;i++){
        fib1[i]=fib1[i-1]+fib1[i-2];
        fib2[i]=fib2[i-1]+fib2[i-2];
    }
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}