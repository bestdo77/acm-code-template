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
int pre[N];
vector<int> G[N];
string s;
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    string s;cin>>s;
    s=" "+s;
    int ans=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1;int r=n;
    while(l<=r){
        if(s[l]!='L'&&s[r]!='R'){
            l++,r--;
        }else if(s[l]!='L'){
            l++;
        }else if(s[r]!='R'){
            r--;
        }else{
            ans+=pre[r]-pre[l-1];
            l++,r--;
        }
    }
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