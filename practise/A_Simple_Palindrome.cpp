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
vector<int> G[N];
char a[6]={'a','e','i','o','u'};
void Atomatic_AC_machine(){
    int n;cin>>n;
    int p=n/5;
    int cnt=n%5;
    for(int i=0;i<5;i++){
        for(int j=1;j<=p;j++) cout<<a[i];
        if(cnt>0) cout<<a[i];
        cnt--;
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