#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int n,k;
pii a[N];
priority_queue<int> anss;
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int j=1;j<=n;j++) cin>>a[j].second;
    sort(a+1,a+1+n);//a[i]一定有序
    int sum=0,mx=0;
    int ans=inf;
    for(int i=1;i<=k;i++){
        sum+=a[i].second;
        mx=a[i].first;
        anss.push(a[i].second);
    }
    ans=min(ans,mx*sum);
    for(int i=k+1;i<=n;i++){
        if(a[i].second<anss.top()){
            sum-=anss.top();
            anss.pop();
            anss.push(a[i].second);
            sum+=a[i].second;
        }
        ans=min(ans,a[i].first*sum);
    }
    cout<<ans<<endl;
    while(anss.size()) anss.pop();
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