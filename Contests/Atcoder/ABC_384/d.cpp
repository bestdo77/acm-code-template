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
map<int,int> vis;
void Atomatic_AC_machine(){
    int n,sum;cin>>n>>sum;
    int csum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        csum+=a[i];
    }
    sum-=sum/csum*csum;
    int sum1=sum;
    sum+=csum;
    if(sum==0){
        cout<<"Yes"<<endl;
        return;
    }
    int sufsum=0;
    vis[0]=1;
    for(int i=n;i>=1;i--){
        sufsum+=a[i];
        vis[sufsum]=1;
    }
    int presum=0;
    for(int i=1;i<=n;i++){
        if(vis[sum-presum]||vis[sum1-presum]){
            cout<<"Yes"<<endl;
            return;
        }
        presum+=a[i];
        // cout<<presum<<" "<<sum-presum<<endl;
    }
    if(vis[sum-presum]||vis[sum1-presum]){
            cout<<"Yes"<<endl;
            return;
    }
    cout<<"No"<<endl;
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