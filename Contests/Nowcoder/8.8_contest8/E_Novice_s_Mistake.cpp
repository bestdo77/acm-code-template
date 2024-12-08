#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=2;
pii a[N];
int pre[N],cnt;
int len(int x){
    int res=0;
    while(x){
        x/=10;
        res++;
    }
    return res;
}
void solve(){
    int n;cin>>n;
    string s="";
    while(s.size()<=25){
        s+=to_string(n);
    }
    s=" "+s;
    for(int i=1;i<=15;i++){
        pre[i]=pre[i-1]*10+(s[i]-'0');
    }
    int cnt=0;
    for(int i=1;i<=10000;i++){//枚举a
        for(int j=i*len(n);j>=max(0ll,i*len(n)-10);j--){//枚举b
            int p=i*len(n)-j;
            if(p==0) continue;
            // cout<<i*n-j<<" "<<pre[p]<<endl;
            if(i*n-j==pre[p]){
                // cout<<i<<" "<<j<<endl;
                a[++cnt]=make_pair(i,j);
            }           
        }
    }
    cout<<cnt-1<<endl;
    for(int i=2;i<=cnt;i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    cnt=0;   
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