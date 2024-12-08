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
vector<int> G[N];
void solve(){
    int l,r;cin>>l>>r;
    int d=r-l;
    int ll=-1,rr=1e9;
    while(ll+1<rr){
        int mid=ll+rr>>1;
        if(((mid+1)*mid/2)<=d) ll=mid;
        else rr=mid;
    }
    cout<<rr<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}