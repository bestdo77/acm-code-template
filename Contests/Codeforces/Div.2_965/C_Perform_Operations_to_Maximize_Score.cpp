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
pii a[N];
vector<int> G[N];
int n,k;
bool check(int x){
    int z=0;//如果是n/2个数字，中位数应该是n/2
    vector<int> els;
    int tmpk=k;
    for(int i=1;i<=n-1;i++){
        if(a[i].first>=x) z++;
        else if(a[i].second==1){
            if(x-a[i].first) els.push_back(x-a[i].first);
            else break;
        }
    }
    reverse(els.begin(),els.end());
    for(auto it:els){
        if(tmpk>=it) tmpk-=it,z++;
        else break;
    }
    return z>=(n+1)/2;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    sort(a+1,a+1+n);
    int ans=0;
    int med=(n)/2;
    for(int i=1;i<=n;i++) if(a[i].second){
        if(i<=med){
            ans=max(a[med+1].first+a[i].first+k,ans);
        }else{
            ans=max(a[med].first+a[i].first+k,ans);
        }
    }
    // cout<<ans<<endl;
    int l=0,r=2e9+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
        // cout<<mid<<endl;
    } 
    ans=max(ans,a[n].first+l);
    cout<<ans<<endl;
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