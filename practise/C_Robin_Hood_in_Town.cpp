#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const double eps=1e-9;
int a[N];
int sum,n,mxpos;
bool check(int x){
    int cnt=0;
    a[mxpos]+=x;
    for(int i=1;i<=n;i++){
        if((double)a[i]<((sum+x)*1.0)/(2.0*n)) cnt++;
    }
    a[mxpos]-=x;
    // cout<<cnt<<endl;
    return cnt>(n/2);
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=2){
        cout<<-1<<endl;
        return;
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        if(a[i]>mx) mx=a[i],mxpos=i;
    }
    sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    int l=-1,r=1e12;
    while(l+1<r){
        int mid=l+r>>1;
        // cout<<mid<<endl;
        if(check(mid)) r=mid;
        else l=mid; 
    }
    cout<<r<<endl;
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