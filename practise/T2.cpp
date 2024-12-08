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
int a[10],b[10];
int check(int x){
    cout <<(sqrt(b[1]*b[1]+x*x)+sqrt(b[2]*b[2]+x*x)+x-sqrt(b[3]*b[3]-b[4]*b[4]+x*x))<<endl;
    if ((sqrt(b[1]*b[1]+x*x)+sqrt(b[2]*b[2]+x*x)+x-sqrt(b[3]*b[3]-b[4]*b[4]+x*x))>0)return 0;
    else return 1;
}
void solve(){
    for (int i=1;i<=4;i++){
        cin >>a[i];
        b[i]=a[i];
        //cout <<b[i]<<endl;
    }
    sort (b+1,b+1+4);
    int l=-1e9-1,r=1e9+1;
    int ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout <<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}