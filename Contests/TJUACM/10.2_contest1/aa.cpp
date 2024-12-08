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
int bp[N],b[N],ans[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)ans[i]=-1;
    for (int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
        if (a[i]==0){
            ans[i]=1;
            continue;
        }
        if (bp[sum%10]!=0)ans[bp[sum%10]]=(i-bp[sum%10]+1);
        b[sum%10]=sum;
        bp[sum%10]=i;
    }
    for (int i=1;i<=n;i++)cout <<ans[i]<<" ";
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