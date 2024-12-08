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
int len;
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;
    len=n-1;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=((s[i]-'0')*(n-len));
        a[len]+=sum;
        len--;
        // cout<<sum<<endl;
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    int len=0;
    for(int i=0;;i++){
        if(a[i]==0) break;
        a[i+1]+=a[i]/10;
        a[i]%=10;
        len++;
    }
    // cout<<endl;
    // for(int i=0;i<len;i++){
    //     cout<<a[i]<<" ";
    // }
    for(int i=len;i--;i>=0){
        cout<<a[i];
    }
    cout<<endl;
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