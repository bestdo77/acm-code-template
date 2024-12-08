#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;
ld eps=1e-13;//<-eps不能太小
int n,k;
int cal(int x,int y){
    if(x>y) return 0;
    return (x+y)*(y-x+1)/2;
}
int calc(int x){
    return cal(k,k+x-1)-cal(k+x,k+n-1);
}
void solve(){
    cin>>n>>k;
    int l=0,r=n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(calc(mid)>=0) r=mid;
        else l=mid;
    }
    if(abs(calc(l+1))<=abs(calc(l))&&l!=n) l++;
    cout<<abs(calc(l))<<endl;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}