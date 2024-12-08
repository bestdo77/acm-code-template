#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[510],ans[510];
int n,m;
int dis(int x,int t){
    int cnt=0;
    while(x/2>=t){
        cnt++;
        x/=2;
    }
    return cnt+min(abs(x-t),abs(x/2-t));
}

int cal(int t){
    for(int i=1;i<=n;i++){
        ans[i]=dis(a[i],t);
    }
    sort(ans+1,ans+1+n);
    int re=accumulate(ans+1,ans+1+n-m,0);
    // cout<<re<<endl;
    return re;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=1000;i++){
        cout<<i<<" "<<cal(i)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}