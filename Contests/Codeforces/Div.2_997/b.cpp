#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
string a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> ans(n+1,inf);
    vector<int> pos(n+1,inf);
    // for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=" "+a[i];
    }
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            cnt+=a[j][i]-'0';
        }
        for(int j=i+1;j<=n;j++){
            if(a[i][j]-'0') cnt--;
            else cnt++;
        }
        // cout<<i<<" "<<cnt+1<<" "<<endl;
        ans[cnt+1]=i;
        pos[i]=cnt+1;
    }
    // cout<<pos[5]<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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