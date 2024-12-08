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
void Atomatic_AC_machine(){
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int last=a[1];
    int cntt=1;
    for(int i=2;i<=n;i++){
        if(a[i]==last) cntt++;
        else{
            last=a[i];
            cntt=1;
        }
        cnt=max(cntt,cnt);
    }
    cnt=max(cntt,cnt);
    cout<<max(n-cnt,0ll)<<endl;
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