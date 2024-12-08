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
map<int,int> cnt;
int nw[N],p;
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(!cnt[a[i]]){
            nw[++p]=a[i];
        }
        cnt[a[i]]++;
    }
    int l=1;
    int ans=0;
    int tans=0;
    int lasti=nw[1];
    for(int i=1;i<=p;i++){
        tans+=cnt[nw[i]];
        while(nw[i]-lasti>1||i-l+1>k){
            tans-=cnt[nw[l]];
            l++;
            if(l==i) lasti=nw[i];
        }
        // cout<<l<<" "<<i<<" "<<tans<<endl;
        lasti=nw[i];
        ans=max(ans,tans);
    }
    cout<<ans<<endl;
    p=0;
    cnt.clear();
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