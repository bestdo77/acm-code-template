#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int pow2[N];
int bigger[N];//后一个数字的2的几次方能大于前一个数字
int lower[N];
int cnt[N];//前一个数字的2的几次方能大于后一个数字
vector<array<int,element>> v;
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        int ans=a[i];
        int cnt=0;
        if(a[i]==1&&a[i-1]>1){
            cout<<-1<<endl;
            return;
        }
        for(int j=1;ans<a[i-1];j++){
            ans*=ans;
            cnt++;
        }
        bigger[i]=cnt;
    }
    for(int i=1;i<=n-1;i++){
        int ans=a[i];
        int cnt=0;
        if(a[i]==1){
            lower[i-1]=inf;
            continue;
        }
        for(int j=1;ans<=a[i+1];j++){
            ans*=ans;
            cnt++;
        }
        lower[i]=max(cnt-1,0LL);
    }
    cnt[1]=0;
    int ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) cnt[i]=max(cnt[i-1]-lower[i-1],0LL);
        if(a[i]<=a[i-1])cnt[i]=cnt[i-1]+bigger[i];
        ans+=cnt[i];
    }
    cout<<ans<<endl;
    return;

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