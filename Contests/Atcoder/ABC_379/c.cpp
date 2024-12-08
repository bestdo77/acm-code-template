#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
set<int> st;
map<int,int> vis;
pii a[N];
int pre[N];
int sum1,sum2;
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=1;i<=m;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].second;
        sum+=a[i].second;
    }
    for(int i=1;i<=m;i++){
        sum1+=a[i].first*a[i].second;
    }
    if(sum!=n){
        cout<<-1<<endl;
        return;
    }
    sort(a+1,a+1+m);
    a[m+1].first=n+1;
    int pos=0;
    int tot=0;
    for(int i=1;i<=m;i++){
        // cout<<a[i].first<<" "<<a[i].second<<" ";
        pos=a[i].first;
        tot+=a[i].second;
        int nxt=min(a[i+1].first-pos,tot);
        tot-=nxt;
        sum2+=(a[i].first+a[i].first+nxt-1)*nxt/2;
        // cout<<pos<<" "<<nxt<<" "<<tot<<endl;
        // cout<<sum2<<endl;
    }
    if(!tot) cout<<sum2-sum1<<endl;
    else cout<<-1<<endl;
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