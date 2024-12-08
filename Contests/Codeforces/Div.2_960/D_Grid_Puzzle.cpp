#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],b[N];
vector<array<int,element>> v;
void solve(){
    int n;cin>>n;
    bool flag12=false,flag34=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!a[i]){
            flag12=flag34=false;
        }else if(a[i]<=2){
            if(flag12){//如果12格已经被覆盖
                flag12=flag34=false;
            }else{
                flag12=true;//覆盖12格
                flag34=false;
                ans++;
            }
        }else if(a[i]>4){
            flag12=flag34=false;
            ans++;
        }else if(a[i]<=4){
            if(flag34&&flag12){
                flag12=flag34=false;
            }else if(flag34+flag12==1){
                ans++;
                flag34^=1;
                flag12^=1;
            }else{
                flag12=flag34=false;
                ans++;
            }
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

